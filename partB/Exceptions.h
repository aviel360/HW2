#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "Game/Game.h"
#include <exception>

namespace mtm{

/*1*/
class IllegalArgument: Exception {

};
/*2*/
class IllegalCell : Exception{

};

/*3*/
class CellEmpty:Exception{

};

/*4*/
class MoveTooFar:Exception{

};

/*5*/
class CellOccupied:Exception{

};

/*6*/
class OutOfRange:Exception{

};

/*7*/
class OutOfAmmo:Exception{

};

/*8*/
class IllegalTarget:
Exception{

};
}

#endif