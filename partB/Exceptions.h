#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <ostream>
#include <string>

namespace mtm{

    class Exceptions: std::exception{
        
        protected:
        std::string name; 

        public:
        Exception();
        Exception(const exception&);
        Exception& operator=(const exception&);
        ~Exception();

        virtual const char* what() const noexcept override{
            std::string general_error_message="A game related error has occurred: ";
            std::string specific_error = this->name;
            return general_error_message.append(specific_error); 
            } 
    };

    class IllegalArgument : public Exceptions
        : name("IllegalArgument")
    {}};
    class IllegalCell : public Exceptions{
        name = IllegalCell;
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