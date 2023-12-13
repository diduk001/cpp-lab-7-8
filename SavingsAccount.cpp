//
// Created by Stepan on 13.12.2023.
//

#include "SavingsAccount.h"
#include "StreamUtils.h"
#include <cstring>


// Input

// Input
std::istream &operator>>(std::istream &in, SavingsAccount &savingsAccount) {
    inputAndCheck(in, "SavingsAccount");

    char equalSign;
    in >> equalSign; // ">>" skips whitespaces
    if (equalSign != '=')
        throw std::invalid_argument("Couldn't find \"=\" in stream");

    char openBrace;
    in >> openBrace;
    if (openBrace != '{')
        throw std::invalid_argument("Couldn't find \"{\" in stream");

    inputAndCheck(in, "balance:");
    double balance;
    in >> balance;
    if (in.fail())
        throw std::invalid_argument("Couldn't read balance");

    char comma;
    in >> comma;
    if (comma != ',')
        throw std::invalid_argument("Couldn't find \",\" in stream");

    inputAndCheck(in, "updateCoefficient:");

    double updateCoefficient;
    in >> updateCoefficient;
    if (in.fail())
        throw std::invalid_argument("Couldn't read updateCoefficient");

    char closeBrace;
    in >> closeBrace;
    if (closeBrace != '}')
        throw std::invalid_argument("Couldn't find \"}\" in stream");

    savingsAccount = SavingsAccount(balance, updateCoefficient);
    return in;
}
