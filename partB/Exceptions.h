#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <ostream>
#include <string>

namespace mtm{

    class Exception: std::exception{
        virtual const char* what() const noexcept override;
    };

    class IllegalArgument : public Exception{
        virtual const char* what() const noexcept override;
    };

    class IllegalCell : public Exception{
        virtual const char* what() const noexcept override;
    };

    class CellEmpty :public Exception{
        virtual const char* what() const noexcept override;
    };

    class MoveTooFar : public Exception{
        virtual const char* what() const noexcept override;
    };

    class CellOccupied : public Exception{
        virtual const char* what() const noexcept override;
    };

    class OutOfRange :public Exception{
        virtual const char* what() const noexcept override;
    };

    class OutOfAmmo : public Exception{
        virtual const char* what() const noexcept override;
    };

    class IllegalTarget :public Exception{
        virtual const char* what() const noexcept override;
    };
    
}

#endif