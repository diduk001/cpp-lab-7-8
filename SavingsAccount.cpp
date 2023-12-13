//
// Created by Stepan on 13.12.2023.
//

#include "SavingsAccount.h"
#include "StreamUtils.h"
#include <cstring>


// Input

// Input
std::istream &operator>>(std::istream &in, SavingsAccount &savingsAccount) {
    skipWhitespaces(in);

    char header[15];
    in.read(header, 14);
    header[14] = '\0';

    if (in.gcount() != 14)
        throw std::length_error("Couldn't read 14 bytes");
    else if (strcmp(header, "SavingsAccount") != 0)
        throw std::invalid_argument("Couldn't find \"SavingsAccount\" in stream");

    char equalSign;
    in >> equalSign; // ">>" skips whitespaces
    if (equalSign != '=')
        throw std::invalid_argument("Couldn't find \"=\" in stream");

    char openBrace;
    in >> openBrace;
    if (openBrace != '{')
        throw std::invalid_argument("Couldn't find \"{\" in stream");

    skipWhitespaces(in);

    char balanceHeader[9];
    in.read(balanceHeader, 8);
    balanceHeader[8] = '\0';
    if (in.gcount() != 8)
        throw std::length_error("Couldn't read 8 bytes");
    else if (strcmp(balanceHeader, "balance:") != 0)
        throw std::invalid_argument("Couldn't find \"balance:\" in stream");

    double balance;
    in >> balance;
    if (in.fail())
        throw std::invalid_argument("Couldn't read balance");

    char comma;
    in >> comma;
    if (comma != ',')
        throw std::invalid_argument("Couldn't find \",\" in stream");

    skipWhitespaces(in);
    char updateCoefficientHeader[19];
    in.read(updateCoefficientHeader, 18);
    updateCoefficientHeader[18] = '\0';
    if (in.gcount() != 18)
        throw std::length_error("Couldn't read 18 bytes");
    else if (strcmp(updateCoefficientHeader, "updateCoefficient:") != 0)
        throw std::invalid_argument("Couldn't find \"updateCoefficient:\" in stream");

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
