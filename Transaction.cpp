//
// Created by Stepan on 14.12.2023.
//

#include "Transaction.h"
#include <iostream>

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
