//
// Created by Stepan on 13.12.2023.
//

#include "CheckingAccount.h"
#include "StreamUtils.h"

// Input
std::istream &operator>>(std::istream &in, CheckingAccount &checkingAccount) {
    inputAndCheck(in, "CheckingAccount");
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

    inputAndCheck(in, "fee:");
    double fee;
    in >> fee;
    if (in.fail())
        throw std::invalid_argument("Couldn't read fee");

    char closeBrace;
    in >> closeBrace;
    if (closeBrace != '}')
        throw std::invalid_argument("Couldn't find \"}\" in stream");

    checkingAccount = CheckingAccount(balance, fee);
    return in;
}