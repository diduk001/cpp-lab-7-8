//
// Created by Stepan on 12.12.2023.
//

#ifndef CPP_LAB_7_8_SAVINGSACCOUNT_H
#define CPP_LAB_7_8_SAVINGSACCOUNT_H

#include "AbstractBankAccount.h"
#include <iostream>

class SavingsAccount : public AbstractBankAccount {
private:
    double updateCoefficient;
public:
    // Default constructor
    SavingsAccount() {
        balance = 0;
        updateCoefficient = 0;
    }

    // Constructor with initial updateCoefficient
    explicit SavingsAccount(double updateCoefficient) {
        if (updateCoefficient < 0) throw std::out_of_range("Update coefficient cannot be negative");

        balance = 0;
        this->updateCoefficient = updateCoefficient;
    }

    // Destructor
    ~SavingsAccount() {
    }

    // Constructor with initial balance and updateCoefficient
    SavingsAccount(double balance, double updateCoefficient) {
        if (balance < 0) throw std::out_of_range("Balance cannot be negative");
        if (updateCoefficient < 0) throw std::out_of_range("Update coefficient cannot be negative");

        this->balance = balance;
        this->updateCoefficient = updateCoefficient;
    }

    // Copy constructor
    SavingsAccount(const SavingsAccount &other) : AbstractBankAccount(other) {
        balance = other.balance;
        updateCoefficient = other.updateCoefficient;
    }

    // Copy assignment operator
    SavingsAccount &operator=(const SavingsAccount &other) {
        balance = other.balance;
        updateCoefficient = other.updateCoefficient;
        return *this;
    }

    // SavingsAccount's balance can be negative
    void withdraw(double amount) {
        if (amount < 0) throw std::out_of_range("Withdraw amount cannot be negative");
        balance -= amount;
    }

    double getUpdateCoefficient() const {
        return updateCoefficient;
    }

    void setUpdateCoefficient(double newUpdateCoefficient) {
        if (newUpdateCoefficient < 0) throw std::out_of_range("Update coefficient cannot be negative");
        this->updateCoefficient = newUpdateCoefficient;
    }

    void update() {
        balance += balance * updateCoefficient;
    }

    void format(std::ostream &out) const {
        out << "SavingsAccount = { balance: " << getBalance() << ", updateCoefficient: "
            << getUpdateCoefficient() << " }";
    }

    friend std::istream &operator>>(std::istream &in, SavingsAccount &savingAccount);
};


#endif //CPP_LAB_7_8_SAVINGSACCOUNT_H
