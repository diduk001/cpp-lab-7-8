#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Transaction.h"

int main() {
    CheckingAccount checkingAccount(100, 10);
    SavingsAccount savingsAccount(100, 0.2);

    std::cout << "Before updating:" << std::endl;
    std::cout << checkingAccount << std::endl;
    std::cout << savingsAccount << std::endl;

    checkingAccount.update();
    savingsAccount.update();

    std::cout << "After updating:" << std::endl;
    std::cout << checkingAccount << std::endl;
    std::cout << savingsAccount << std::endl;

    Transaction deposit10toCheckingAccount = Transaction(&checkingAccount, 10);
    Transaction withdraw10fromSavingAccount = Transaction(&savingsAccount, 10);
    deposit10toCheckingAccount.execute();
    withdraw10fromSavingAccount.execute();

    std::cout << "After deposit and withdraw:" << std::endl;
    std::cout << checkingAccount << std::endl;
    std::cout << savingsAccount << std::endl;

    Transaction betweenAccounts = Transaction(&checkingAccount, &savingsAccount, 10);
    betweenAccounts.execute();

    std::cout << "After executing transaction:" << std::endl;
    std::cout << checkingAccount << std::endl;
    std::cout << savingsAccount << std::endl;

    return 0;
}
