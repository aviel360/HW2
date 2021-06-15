#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

namespace mtm{
    class Exceptions : std::exception{
        class IllegalArgument{};
        class IllegalCell{};
        class CellEmty{};

    };
}

#endif