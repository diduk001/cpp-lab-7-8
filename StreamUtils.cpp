//
// Created by Stepan on 13.12.2023.
//

#include "StreamUtils.h"
#include <cstring>
#include <sstream>

// Skips whitespaces in stream
void skipWhitespaces(std::istream &in) {
    while (isspace(in.peek()))
        in.get();
}

// Reads a string from stream and checks if it's equal to expected
void inputAndCheck(std::istream &in, const std::string &expected) {
    skipWhitespaces(in);
    size_t expectedSize = expected.size();
    char buffer[expectedSize + 1];
    in.read(buffer, expectedSize);
    buffer[expectedSize] = '\0';
    if (in.gcount() != expectedSize) {
        std::stringstream ss;
        ss << "Couldn't read " << expectedSize << " bytes";
        throw std::length_error(ss.str());
    } else if (std::strcmp(buffer, expected.c_str()) != 0) {
        std::stringstream ss;
        ss << "Couldn't find \"" << expected << "\" bytes";
        throw std::invalid_argument(ss.str());
    }
}