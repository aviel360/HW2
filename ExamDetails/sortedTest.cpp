#include <iostream>
#include "SortedList.h"

void Test();
using std::cout;
using std::endl;
using std::string;
using namespace mtm;
int main(){
    op("Test");
    Test();
}

void Test(){
    op("EmptyList");
    SortedList<string> list1;
    op("RemoveWhileEmpty");
    try{
        list1.remove(list1.begin());
    } catch (std::out_of_range e){
        op("OutOfBounds");
    }
}

void op(string s){
    cout << "-----" << s << "-----" << endl;
}