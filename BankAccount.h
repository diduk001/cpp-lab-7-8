//
// Created by Stepan on 11.12.2023.
//

#ifndef CPP_LAB_7_8_BANKACCOUNT_H
#define CPP_LAB_7_8_BANKACCOUNT_H

#include <stdexcept>

class BankAccount {
protected:
    double balance;
public:
    BankAccount() {
        balance = 0;
    }

    virtual ~BankAccount() {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount < 0) throw std::out_of_range("Deposit amount cannot be negative");
        balance += amount;
    }

    virtual void withdraw(double amount) = 0;

    bool operator==(const BankAccount &other) const {
        return balance == other.balance;
    }

    virtual void format(std::ostream &out) const = 0;

    friend std::ostream &operator<<(std::ostream &out, const BankAccount &bankAccount);
};


#endif //CPP_LAB_7_8_BANKACCOUNT_H
