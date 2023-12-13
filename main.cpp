#include <iostream>
#include <fstream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Transaction.h"
#include "User.h"

void executeTransaction(CheckingAccount &checkingAccount, SavingsAccount &savingsAccount);

int main() {
    CheckingAccount checkingAccount(100, 10);
    SavingsAccount savingsAccount(100, 0.1);
    User user("User", checkingAccount, savingsAccount);

    while (true) {
        std::cout << "Current user:" << std::endl;
        std::cout << user << std::endl << std::endl;

        std::cout << "Choose command:" << std::endl;
        std::cout << "1. Execute transaction" << std::endl;
        std::cout << "2. Change user name" << std::endl;
        std::cout << "3. Update accounts" << std::endl;
        std::cout << "4. Exit" << std::endl;

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
            break;
        } else {
            std::cout << "Unknown command" << std::endl;
        }
    }

    std::string outputFilename;
    std::cout << "Enter output file name > ";
    std::cin >> outputFilename;

    std::ofstream out(outputFilename.c_str());
    out << user << std::endl;
    out.close();

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
