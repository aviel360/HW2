#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <ostream>

namespace mtm{
    class Exceptions : std::exception {
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