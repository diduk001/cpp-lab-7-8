//
// Created by Stepan on 13.12.2023.
//

#include "AbstractBankAccount.h"
#include <iostream>

std::ostream &operator<<(std::ostream &out, const AbstractBankAccount &bankAccount) {
    bankAccount.format(out);
    return out;
}
