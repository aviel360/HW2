#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

namespace mtm{
    class Exceptions : std::exception {

        public:
        class IllegalArgument{};
        class IllegalCell{};
        class CellEmpty{};
        class MoveTooFar{};
        class CellOccupied{};
        class OutOfRange{};
        class OutOfAmmo{};
        class IllegalTarget{};
    };
}
#endif