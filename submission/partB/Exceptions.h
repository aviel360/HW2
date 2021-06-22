#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <ostream>

namespace mtm{

    class Exception: std::exception{
    public:    
        virtual const char* what() const noexcept = 0;
    };

    class IllegalArgument : public Exception{
    public:    
        virtual const char* what() const noexcept override;
    };

    class IllegalCell : public Exception{
    public:    
        virtual const char* what() const noexcept override;
    };

    class CellEmpty :public Exception{
    public:    
        virtual const char* what() const noexcept override;
    };

    class MoveTooFar : public Exception{
    public:    
        virtual const char* what() const noexcept override;
    };

    class CellOccupied : public Exception{
    public:    
        virtual const char* what() const noexcept override;
    };

    class OutOfRange :public Exception{
    public:    
        virtual const char* what() const noexcept override;
    };

    class OutOfAmmo : public Exception{
    public:    
        virtual const char* what() const noexcept override;
    };

    class IllegalTarget :public Exception{
    public:    
        virtual const char* what() const noexcept override;
    };
    
}

#endif