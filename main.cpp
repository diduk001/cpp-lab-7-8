#include <iostream>
#include <fstream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Transaction.h"
#include "Customer.h"

void executeTransaction(CheckingAccount &checkingAccount, SavingsAccount &savingsAccount);

int main() {
    CheckingAccount checkingAccount(100, 10);
    SavingsAccount savingsAccount(100, 0.1);
    Customer user("Customer", checkingAccount, savingsAccount);

    while (true) {
        std::cout << "Current user:" << std::endl;
        std::cout << user << std::endl << std::endl;

        std::cout << "Choose command:" << std::endl;
        std::cout << "1. Execute transaction" << std::endl;
        std::cout << "2. Change user name" << std::endl;
        std::cout << "3. Update accounts" << std::endl;
        std::cout << "4. Write user in file" << std::endl;
        std::cout << "5. Enter user from file" << std::endl;
        std::cout << "6. Exit" << std::endl;

        int command;
        std::cin >> command;

        if (command == 1) {
            executeTransaction(user.accessCheckingAccount(), user.accessSavingsAccount());
        } else if (command == 2) {
            std::string newName;
            std::cout << "Enter new name:" << std::endl;
            std::cin >> newName;

            user.setName(newName);
        } else if (command == 3) {
            user.accessCheckingAccount().update();
            user.accessSavingsAccount().update();
        } else if (command == 4) {
            std::string outputFilename;
            std::cout << "Enter output file name:" << std::endl;
            std::cin >> outputFilename;

            std::ofstream out(outputFilename.c_str());
            out << user << std::endl;
            out.close();
        } else if (command == 5) {
            std::string inputFilename;
            std::cout << "Enter input file name:" << std::endl;
            std::cin >> inputFilename;

            std::ifstream in(inputFilename.c_str());
            in >> user;
            in.close();
        } else if (command == 6) {
            break;
        } else {
            std::cout << "Unknown command" << std::endl;
        }
    }

    return 0;
}

void executeTransaction(CheckingAccount &checkingAccount, SavingsAccount &savingsAccount) {
    std::cout << "Choose transaction type:" << std::endl;
    std::cout << "1. From checking account to savings account" << std::endl;
    std::cout << "2. From savings account to checking account" << std::endl;
    std::cout << "3. To/From checking account" << std::endl;
    std::cout << "4. To/From savings account" << std::endl;
    std::cout << "5. Return back" << std::endl;

    int command;
    std::cin >> command;

    if (command < 1 || command > 5) {
        std::cout << "Unknown command" << std::endl;
        return;
    } else if (command == 5) {
        return;
    }

    double amount;
    std::cout << "Enter amount:" << std::endl;
    std::cin >> amount;

    Transaction transaction;
    if ((command == 1 || command == 2) && amount < 0) {
        std::cout << "Amount cannot be negative" << std::endl;
        return;
    }
    if (command == 1) {
        transaction = Transaction(&checkingAccount, &savingsAccount, amount);
    } else if (command == 2) {
        transaction = Transaction(&savingsAccount, &checkingAccount, amount);
    } else if (command == 3) {
        transaction = Transaction(&checkingAccount, amount);
    } else if (command == 4) {
        transaction = Transaction(&savingsAccount, amount);
    }

    std::cout << transaction << std::endl;
    transaction.execute();
}
