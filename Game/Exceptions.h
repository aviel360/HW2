#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <ostream>

namespace mtm{
    class Exceptions : std::exception {};
    class IllegalArgument : Exceptions{};
    class IllegalCell : Exceptions{};
    class CellEmpty : Exceptions{};
    class MoveTooFar : Exceptions{};
    class CellOccupied : Exceptions{};
    class OutOfRange : Exceptions{};
    class OutOfAmmo : Exceptions{};
    class IllegalTarget : Exceptions{};
    
}

#endif