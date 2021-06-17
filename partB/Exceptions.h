#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

namespace mtm{


    class Exceptions: std::exception{
        
        public:
        const char* error_message; 

        virtual const char* what() const noexcept override{
            return this->error_message;
            } 
    };

    class IllegalArgument : public Exceptions{
        const char* error_message = "A game related error has occurred: IllegalArgument";
    };
    class IllegalCell : public Exceptions{
        const char* error_message = "A game related error has occurred: IllegalCell";
    };
    class CellEmpty :public Exceptions{
        const char* error_message = "A game related error has occurred: CellEmpty";
    };
    class MoveTooFar : public Exceptions{
        const char* error_message = "A game related error has occurred:  MoveTooFar";
    };
    class CellOccupied : public Exceptions{
        const char* error_message = "A game related error has occurred: CellOccupied";
    };
    class OutOfRange :public Exceptions{
        const char* error_message = "A game related error has occurred: OutOfRange";

    };
    class OutOfAmmo : public Exceptions{
        const char* error_message = "A game related error has occurred: OutOfAmmo";
    };
    class IllegalTarget :public Exceptions{
        const char* error_message = "A game related error has occurred:  IllegalTarget";
    };

    
    
}

#endif