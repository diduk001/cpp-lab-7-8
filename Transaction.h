//
// Created by Stepan on 12.12.2023.
//

#ifndef CPP_LAB_7_8_TRANSACTION_H
#define CPP_LAB_7_8_TRANSACTION_H

#include "BankAccount.h"

class Transaction {
private:
    BankAccount *from;
    BankAccount *to;
    double amount;
public:
    // Default constructor
    Transaction() {
        from = NULL;
        to = NULL;
        amount = 0;
    }

    // Constructor with initial from, to and amount
    Transaction(BankAccount *from, BankAccount *to, double amount) {
        if (amount < 0) throw std::out_of_range("Amount cannot be negative");

        this->from = from;
        this->to = to;
        this->amount = amount;
    }

    // Constructor with only one account
    Transaction(BankAccount *account, double amount) {
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

    // Getters
    BankAccount *getFrom() const {
        return from;
    }

    BankAccount *getTo() const {
        return to;
    }

    double getAmount() const {
        return amount;
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

std::ostream &operator<<(std::ostream &out, const Transaction &transaction) {
    out << "Transaction = { ";
    if (transaction.getFrom() != NULL) {
        out << "From: ";
        out << *transaction.getFrom() << ", ";
    }
    if (transaction.getTo() != NULL) {
        out << "To: ";
        out << *transaction.getTo() << ", ";
    }
    out << "Amount: " << transaction.getAmount() << " }";
    return out;
}


#endif //CPP_LAB_7_8_TRANSACTION_H
