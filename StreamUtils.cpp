//
// Created by Stepan on 13.12.2023.
//

#include "StreamUtils.h"

void skipWhitespaces(std::istream &in) {
    while (isspace(in.peek()))
        in.get();
}

