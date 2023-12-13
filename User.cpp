//
// Created by Stepan on 13.12.2023.
//
#include "User.h"
#include "StreamUtils.h"

std::istream &operator>>(std::istream &in, User &user) {
    skipWhitespaces(in);

    char header[5];
    in.read(header, 4);
    header[4] = '\0';

    if (in.gcount() != 4)
        throw std::length_error("Couldn't read 4 bytes");
    else if (strcmp(header, "User") != 0)
        throw std::invalid_argument("Couldn't find \"User\" in stream");

    char equalSign;
    in >> equalSign; // ">>" skips whitespaces
    if (equalSign != '=')
        throw std::invalid_argument("Couldn't find \"=\" in stream");

    char openBrace;
    in >> openBrace;
    if (openBrace != '{')
        throw std::invalid_argument("Couldn't find \"{\" in stream");

    skipWhitespaces(in);

    char nameHeader[6];
    in.read(nameHeader, 5);
    nameHeader[5] = '\0';
    if (in.gcount() != 5)
        throw std::length_error("Couldn't read 5 bytes");
    else if (strcmp(nameHeader, "name:") != 0)
        throw std::invalid_argument("Couldn't find \"name:\" in stream");

    std::string name;
    in >> name;
    if (in.fail())
        throw std::invalid_argument("Couldn't read name");
    if (name.size() >= 2 && name[0] == '"' && name[name.size() - 1] == '"') // Remove wrapping
        name = name.substr(1, name.size() - 2);

    char comma;
    in >> comma;
    if (comma != ',')
        throw std::invalid_argument("Couldn't find \",\" in stream");

    skipWhitespaces(in);

    char checkingAccountHeader[17];
    in.read(checkingAccountHeader, 16);
    checkingAccountHeader[16] = '\0';
    if (in.gcount() != 16)
        throw std::length_error("Couldn't read 16 bytes");
    else if (strcmp(checkingAccountHeader, "checkingAccount:") != 0) {
        std::cerr << checkingAccountHeader << '\n';
        throw std::invalid_argument("Couldn't find \"checkingAccount:\" in stream");
    }

    CheckingAccount checkingAccount;
    in >> checkingAccount;

    in >> comma;
    if (comma != ',')
        throw std::invalid_argument("Couldn't find \",\" in stream");

    skipWhitespaces(in);

    char savingsAccountHeader[16];
    in.read(savingsAccountHeader, 15);
    savingsAccountHeader[15] = '\0';
    if (in.gcount() != 15)
        throw std::length_error("Couldn't read 15 bytes");
    else if (strcmp(savingsAccountHeader, "savingsAccount:") != 0)
        throw std::invalid_argument("Couldn't find \"savingsAccount:\" in stream");

    SavingsAccount savingsAccount;
    in >> savingsAccount;

    char closeBrace;
    in >> closeBrace;
    if (closeBrace != '}')
        throw std::invalid_argument("Couldn't find \"}\" in stream");

    user = User(name, checkingAccount, savingsAccount);
    return in;
}

