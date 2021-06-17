#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

namespace mtm{

    class A {
        public:
        int hi;
    }

    class B : public A {
        hi = 3;
    }



    class Exceptions: std::exception{
        
        public:
        const char* error_message; 

        virtual const char* what() const noexcept override{
            return this->error_message;
            } 
    };

    class IllegalArgument : public Exceptions
        : name("IllegalArgument")
    {};
    class IllegalCell : Exceptions{
        error_message = "A game related error has occurred: IllegalCell";
    };
    class CellEmpty :public Exceptions{
        name = CellEmpty;
    };
    class MoveTooFar : public Exceptions{
        name = MoveTooFar;
    };
    class CellOccupied : public Exceptions{
        name = MoveTooFar 
    };
    class OutOfRange :public Exceptions{};
    class OutOfAmmo : public Exceptions{};
    class IllegalTarget :public Exceptions{};

    
    
}

#endif