//
// Created by Stepan on 13.12.2023.
//

#include "CheckingAccount.h"
#include "StreamUtils.h"

// Input
std::istream &operator>>(std::istream &in, CheckingAccount &checkingAccount) {
    skipWhitespaces(in);

    char header[16];
    in.read(header, 15);
    header[15] = '\0';

    if (in.gcount() != 15)
        throw std::length_error("Couldn't read 15 bytes");
    else if (strcmp(header, "CheckingAccount") != 0)
        throw std::invalid_argument("Couldn't find \"CheckingAccount\" in stream");

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
    char feeHeader[5];
    in.read(feeHeader, 4);
    feeHeader[4] = '\0';
    if (in.gcount() != 4)
        throw std::length_error("Couldn't read 4 bytes");
    else if (strcmp(feeHeader, "fee:") != 0)
        throw std::invalid_argument("Couldn't find \"fee:\" in stream");

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