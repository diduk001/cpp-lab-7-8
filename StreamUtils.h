//
// Created by Stepan on 13.12.2023.
//

#ifndef CPP_LAB_7_8_STREAMUTILS_H
#define CPP_LAB_7_8_STREAMUTILS_H

#include <iostream>

// Skips whitespaces in stream
void skipWhitespaces(std::istream &in);

// Reads a string from stream and checks if it's equal to expected
void inputAndCheck(std::istream &in, const std::string &expected);

#endif //CPP_LAB_7_8_STREAMUTILS_H
