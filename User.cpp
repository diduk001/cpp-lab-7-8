//
// Created by Stepan on 13.12.2023.
//
#include "User.h"
#include "StreamUtils.h"

std::istream &operator>>(std::istream &in, User &user) {
    inputAndCheck(in, "User");

    char equalSign;
    in >> equalSign; // ">>" skips whitespaces
    if (equalSign != '=')
        throw std::invalid_argument("Couldn't find \"=\" in stream");

    char openBrace;
    in >> openBrace;
    if (openBrace != '{')
        throw std::invalid_argument("Couldn't find \"{\" in stream");

    inputAndCheck(in, "name:");

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

    inputAndCheck(in, "checkingAccount:");
    CheckingAccount checkingAccount;
    in >> checkingAccount;

    in >> comma;
    if (comma != ',')
        throw std::invalid_argument("Couldn't find \",\" in stream");

    inputAndCheck(in, "savingsAccount:");
    SavingsAccount savingsAccount;
    in >> savingsAccount;

    char closeBrace;
    in >> closeBrace;
    if (closeBrace != '}')
        throw std::invalid_argument("Couldn't find \"}\" in stream");

    user = User(name, checkingAccount, savingsAccount);
    return in;
}

