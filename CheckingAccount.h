//
// Created by Stepan on 12.12.2023.
//

#ifndef CPP_LAB_7_8_CHECKINGACCOUNT_H
#define CPP_LAB_7_8_CHECKINGACCOUNT_H

#include "BankAccount.h"
#include <iostream>
#include <exception>
#include <cstring>

class CheckingAccount : public BankAccount {
protected:
    double fee;
public:
    // Default constructor
    CheckingAccount() {
        balance = 0;
        fee = 0;
    }

    // Constructor with initial fee
    explicit CheckingAccount(double fee) {
        if (fee < 0) throw std::out_of_range("Fee cannot be negative");

        balance = 0;
        this->fee = fee;
    }

    // Constructor with initial balance and fee
    CheckingAccount(double balance, double fee) {
        if (balance < 0) throw std::out_of_range("Balance cannot be negative");
        if (fee < 0) throw std::out_of_range("Fee cannot be negative");

        this->balance = balance;
        this->fee = fee;
    }

    // Copy constructor
    CheckingAccount(const CheckingAccount &other) : BankAccount(other) {
        balance = other.balance;
        fee = other.fee;
    }

    // Destructor
    ~CheckingAccount() {
    }

    // Copy assignment operator
    CheckingAccount &operator=(const CheckingAccount &other) {
        balance = other.balance;
        fee = other.fee;
        return *this;
    }

    // CheckingAccount's balance can be negative
    void withdraw(double amount) {
        if (amount < 0) throw std::out_of_range("Withdraw amount cannot be negative");
        balance -= amount;
    }

    double getFee() const {
        return fee;
    }

    void setFee(double newFee) {
        this->fee = newFee;
    }

    void update() {
        balance -= fee;
    }

    void format(std::ostream &out) const {
        out << "CheckingAccount = { balance: " << getBalance() << ", fee: " << getFee() << " }";
    }

    friend std::istream &operator>>(std::istream &in, CheckingAccount &checkingAccount);
};


#endif //CPP_LAB_7_8_CHECKINGACCOUNT_H
