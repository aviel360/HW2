#include <iostream>
#include "SortedList.h"

void Test();
using std::cout;
using std::endl;
using std::string;
using namespace mtm;
void op(string s);

void printList(SortedList<string> list) {
    for (auto it = list.begin(); !(it == list.end()); ++it) {
        cout << *it << endl;
    }
    cout << endl;
}

string addon(string str)
{
    if(str == "A"){
        return "Yes!";
    }
    return "NO!!";
}

bool condition(string str){
    if(str == "NO!!"){
        return false;
    }
    return true;
}

void op(string s){
    cout << "-----" << s << "-----" << endl;
}

void op(int x){
    cout << "-----" << x << "-----" << endl;
}

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
    } catch (std::out_of_range& e){
        op(e.what());
    }
    try{
        list1.remove(list1.end());
    } catch (std::out_of_range& e){
        op(e.what());
    }
    op("Insert");
    list1.insert("B");
    list1.insert("B");
    list1.insert("A");
    list1.insert("F");
    list1.insert("B");
    list1.insert("C");
    list1.insert("D");
    list1.insert("C");
    printList(list1);
    op("Copy");
    SortedList<string> list2 = list1;
    auto it = list1.begin();
    while(*it != "C"){
        it++;
    }
    auto temp = it;
    temp++;
    op("RemoveC");
    list1.remove(it);
    list1.remove(temp);
    printList(list1);
    list1.insert("K");
    try{
        do{
            auto itA = list2.begin();
            list2.remove(itA);
        } while(1);
        list2.remove(list2.begin());
    } catch (std::out_of_range& e) {
        op(e.what());
    }
    list2.insert("Empty");
    printList(list1);
    printList(list2);
    list2 = list1;
    try{
        while(1){
            list1.remove(list1.begin());
        }
    }catch (std::out_of_range& e){
        op(e.what());
    }
    list1.insert("Empty");
    printList(list1);
    printList(list2);
    SortedList<string> list3 = list2.apply(addon);
    printList(list3);
    printList(list2);
    list2 = list3.filter(condition);
    printList(list2);
    list1 = list3;
    list3 = list2;
    printList(list1);
    printList(list3);
    list3.remove(list3.begin());
    op(list3.length());
    op(list2.length());
    op(list1.length());

}


