#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"

int main() {
    CheckingAccount checkingAccount(100, 10);
    std::cout << checkingAccount << std::endl;

    SavingsAccount savingsAccount(100, 1.2);
    std::cout << savingsAccount << std::endl;

    return 0;
}
