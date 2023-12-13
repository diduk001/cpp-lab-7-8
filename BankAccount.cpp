//
// Created by Stepan on 13.12.2023.
//

#include "BankAccount.h"
#include <iostream>

std::ostream &operator<<(std::ostream &out, const BankAccount &bankAccount) {
    bankAccount.format(out);
    return out;
}
