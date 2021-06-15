#include <exception>

/*1*/
class IllegalArgument:mtm::Exception{

};
/*2*/
class IllegalCell:mtm::Exception{

};

/*3*/
class CellEmpty:mtm::Exception{

};

/*4*/
class MoveTooFar:mtm::Exception{

};

/*5*/
class CellOccupied:mtm::Exception{

};

/*6*/
class OutOfRange:mtm::Exception{

};

/*7*/
class OutOfAmmo:mtm::Exception{

};

/*8*/
class IllegalTarget:mtm::Exception{

};

