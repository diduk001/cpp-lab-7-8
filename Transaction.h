//
// Created by Stepan on 12.12.2023.
//

#ifndef CPP_LAB_7_8_TRANSACTION_H
#define CPP_LAB_7_8_TRANSACTION_H

#include "AbstractBankAccount.h"

class Transaction {
private:
    AbstractBankAccount *from;
    AbstractBankAccount *to;
    double amount;
public:
    // Default constructor
    Transaction() {
        from = NULL;
        to = NULL;
        amount = 0;
    }

    // Constructor with initial from, to and amount
    Transaction(AbstractBankAccount *from, AbstractBankAccount *to, double amount) {
        if (amount < 0) throw std::out_of_range("Amount cannot be negative");

        this->from = from;
        this->to = to;
        this->amount = amount;
    }

    // Constructor with only one account
    Transaction(AbstractBankAccount *account, double amount) {
        if (amount < 0) {
            this->from = account;
            this->to = NULL;
            this->amount = -amount;
        } else {
            this->from = NULL;
            this->to = account;
            this->amount = amount;
        }
    }

    // Execute transaction
    void execute() {
        if (from != NULL) {
            from->withdraw(amount);
        }
        if (to != NULL) {
            to->deposit(amount);
        }
    }

};


#endif //CPP_LAB_7_8_TRANSACTION_H
