//
// Created by Stepan on 11.12.2023.
//

#ifndef CPP_LAB_7_8_ABSTRACTBANKACCOUNT_H
#define CPP_LAB_7_8_ABSTRACTBANKACCOUNT_H

#include <stdexcept>

class AbstractBankAccount {
protected:
    double balance;
public:
    AbstractBankAccount() {
        balance = 0;
    }

    virtual ~AbstractBankAccount() {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount < 0) throw std::out_of_range("Deposit amount cannot be negative");
        balance += amount;
    }

    virtual void withdraw(double amount) = 0;

    bool operator==(const AbstractBankAccount &other) const {
        return balance == other.balance;
    }

    virtual void format(std::ostream &out) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AbstractBankAccount &bankAccount) {
    bankAccount.format(out);
    return out;
}


#endif //CPP_LAB_7_8_ABSTRACTBANKACCOUNT_H
