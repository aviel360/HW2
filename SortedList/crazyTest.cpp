#include <iostream>
#include "SortedList.h"
#include <assert.h>
#include "testClass.h"

//
#define TEST(num) cout << endl << "TEST " << (num) << endl;

using std::cout;
using std::endl;
using std::string;
using namespace mtm;
using mtm::SortedList;
using mtm::TestClass;
using mtm::externalConstructor;

string getLen(string str)
{
    return std::to_string(str.length());
}

template<class T>
void printList(SortedList<T> list) {
    for (auto it = list.begin(); !(it == list.end()); ++it) {
        cout << *it << endl;
    }
    cout << endl;
}



bool isEven(int num)
{
   return !(num % 2);
}

bool isOdd(int num)
{
   return !isEven(num);
}

bool isTreven(int num)
{
   return !(num % 3);
}

int addThree(int num)
{
   return num + 3;
}

int subtract3Multiply2(int num)
{
   return (num-3)*2;
}

int zero(int num)
{
   return 0;
}

int multiplyNegative1(int num)
{
   return -num;
}

int square(int num)
{
   return num*num;
}

int turnEvensToNegatives(int num)
{
   if (isEven(num))
   {
       return -num;
   }
   return num;
}

double Polynomial(int num)
{
   return num*(num-8);
}

bool punky(TestClass d)
{
   if (d < externalConstructor(90, 4))
   {
       return true;
   }
   return false;
}


TestClass funky(TestClass d)
{
   return externalConstructor(d.x * (d.x - 13), 0);
}

void listTest1()
{
   cout << "Running test1 - basics1... ";
   SortedList<int> list1 = SortedList<int>();
   //int x = list1.length();
   //cout << x;
   list1.insert(0);
   list1.insert(1);
   list1.insert(2);
   list1.insert(3);
   list1.insert(-4);
   list1.insert(5);
   list1.insert(11);
   list1.insert(6);
   list1.insert(7);
   list1.insert(8);
   list1.insert(3);
   list1.insert(9);
   list1.insert(10);


   cout << "[OK]" << endl;
}

void listTest2()
{
   cout << "Running test2 - basics2... ";

   // List creation
   SortedList<int> list1 = SortedList<int>();
   list1.insert(1);
   list1.insert(2);
   list1.insert(5);
   list1.insert(5);
   list1.insert(4);
   list1.insert(3);
   list1.insert(3);
   list1.insert(3);
   list1.insert(3);
   list1.insert(9);
   list1.insert(8);

   // Check insert and iterator
   SortedList<int>::const_iterator iter = list1.begin();
   assert(*(iter) == 1);
   assert(*(++iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(*(++iter) == 8);
   assert(*(++iter) == 9);
   assert(++iter == list1.end());
   assert(list1.length() == 11);

   // Check copy constructor
   SortedList<int> list2 = list1;
   iter = list2.begin();
   assert(*(iter) == 1);
   assert(*(++iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(*(++iter) == 8);
   assert(*(++iter) == 9);
   assert(++iter == list2.end());
   assert(list2.length() == 11);

   // Check remove function - delete from start
   iter = list2.begin();
   list2.remove(iter);
   iter = list2.begin();

   assert(*(iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(*(++iter) == 8);
   assert(*(++iter) == 9);
   assert(++iter == list2.end());
   assert(list2.length() == 10);

   // Check remove function - delete from mid
   iter = list2.begin();
   ++iter;
   ++iter;
   ++iter;
   list2.remove(iter);
   iter = list2.begin();
   printList(list2);

   assert(*(iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(*(++iter) == 8);
   assert(*(++iter) == 9);
   assert(++iter == list2.end());
   assert(list2.length() == 9);


   // Check remove function - delete from mid
   iter = list2.begin();
   ++iter; ++iter; ++iter; ++iter; ++iter; ++iter; ++iter;
   list2.remove(iter);
   iter = list2.begin();

   assert(*(iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(*(++iter) == 9);
   assert(++iter == list2.end());
   assert(list2.length() == 8);


   // Check remove function - delete from end
   iter = list2.begin();
   ++iter; ++iter; ++iter; ++iter; ++iter; ++iter; ++iter;
   list2.remove(iter);
   iter = list2.begin();

   assert(*(iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(++iter == list2.end());
   assert(list2.length() == 7);


   // Check the original list is unchanged
   iter = list1.begin();
   assert(*(iter) == 1);
   assert(*(++iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(*(++iter) == 8);
   assert(*(++iter) == 9);
   assert(++iter == list1.end());

   // Check other operator++
   iter = list1.begin();
   assert(*(++iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(*(++iter) == 8);
   assert(*(++iter) == 9);
   assert(++iter == list1.end());

   // Check assignment operator
   SortedList<int> list3;
   list3 = list2;
   iter = list3.begin();

   assert(*(iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(++iter == list3.end());

   try { ++iter; }
   catch(std::out_of_range& err) {}

   list3 = list1;
   iter = list3.begin();
   assert(*(iter) == 1);
   assert(*(++iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(*(++iter) == 8);
   assert(*(++iter) == 9);
   assert(++iter == list3.end());

   list3 = SortedList<int>();
   SortedList<int> list4 = list3;
   assert(list3.length() == 0);
   assert(list4.length() == 0);
   iter = list3.begin();
   assert(iter == list3.end());

   list4 = list1;
   list4 = list4;
   list4 = list4;
   list4 = list4;
   iter = list4.begin();
   assert(*(iter) == 1);
   assert(*(++iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(*(++iter) == 8);
   assert(*(++iter) == 9);
   assert(++iter == list4.end());
   assert(list4.length() == 11);


   list1 = list1;
   list1 = list1;
   list1 = list1;
   list1 = list1;
   iter = list1.begin();
   assert(*(iter) == 1);
   assert(*(++iter) == 2);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 3);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 5);
   assert(*(++iter) == 8);
   assert(*(++iter) == 9);
   assert(++iter == list1.end());
   assert(list1.length() == 11);
   cout << "[OK]" << endl;
}

void listTest3()
{
   cout << "Running test3 - filter...  ";
   SortedList<int> list1 = SortedList<int>();

   list1.insert(14);
   list1.insert(18);
   list1.insert(62);
   list1.insert(47);
   list1.insert(31);
   list1.insert(59);
   list1.insert(96);
   list1.insert(69);

   SortedList<int>::const_iterator iter = list1.begin();
   assert(*(iter) == 14);
   assert(*(++iter) == 18);
   assert(*(++iter) == 31);
   assert(*(++iter) == 47);
   assert(*(++iter) == 59);
   assert(*(++iter) == 62);
   assert(*(++iter) == 69);
   assert(*(++iter) == 96);
   assert(++iter == list1.end());
   assert(list1.length() == 8);

   SortedList<int> list2 = list1.filter(isEven);
   iter = list2.begin();
   assert(*(iter) == 14);
   assert(*(++iter) == 18);
   assert(*(++iter) == 62);
   assert(*(++iter) == 96);
   assert(++iter == list2.end());
   assert(list2.length() == 4);

   list2 = list1.filter(isOdd);
   iter = list2.begin();
   assert(*(iter) == 31);
   assert(*(++iter) == 47);
   assert(*(++iter) == 59);
   assert(*(++iter) == 69);
   assert(++iter == list2.end());
   assert(list2.length() == 4);

   list2 = list1.filter(isTreven);
   iter = list2.begin();
   assert(*(iter) == 18);
   assert(*(++iter) == 69);
   assert(*(++iter) == 96);
   assert(++iter == list2.end());
   assert(list2.length() == 3);

   cout << "[OK]" << endl;
}

void listTest4()
{
   cout << "Running test4 - apply...   ";
   SortedList<int> list1 = SortedList<int>();
   list1.insert(6);
   list1.insert(2);
   list1.insert(4);
   list1.insert(3);
   list1.insert(9);
   list1.insert(-3);
   list1.insert(1);
   list1.insert(-1);

   SortedList<int>::const_iterator iter = list1.begin();
   //*iter = 5;   <-- Verify actually const

   SortedList<int> list2 = list1.apply(addThree);
   iter = list2.begin();
   assert(*(iter) == 0);
   assert(*(++iter) == 2);
   assert(*(++iter) == 4);
   assert(*(++iter) == 5);
   assert(*(++iter) == 6);
   assert(*(++iter) == 7);
   assert(*(++iter) == 9);
   assert(*(++iter) == 12);
   assert(++iter == list2.end());
   assert(list1.length() == 8);


   list2 = list1.apply(subtract3Multiply2);
   iter = list2.begin();
   assert(*(iter) == -12);
   assert(*(++iter) == -8);
   assert(*(++iter) == -4);
   assert(*(++iter) == -2);
   assert(*(++iter) == 0);
   assert(*(++iter) == 2);
   assert(*(++iter) == 6);
   assert(*(++iter) == 12);
   assert(++iter == list2.end());
   assert(list1.length() == 8);


   list2 = list1.apply(zero);
   iter = list2.begin();
   assert(*(iter) == 0);
   assert(*(++iter) == 0);
   assert(*(++iter) == 0);
   assert(*(++iter) == 0);
   assert(*(++iter) == 0);
   assert(*(++iter) == 0);
   assert(*(++iter) == 0);
   assert(*(++iter) == 0);
   assert(++iter == list2.end());
   assert(list1.length() == 8);

   list2 = list1.apply(multiplyNegative1);
   iter = list2.begin();
   assert(*(iter) == -9);
   assert(*(++iter) == -6);
   assert(*(++iter) == -4);
   assert(*(++iter) == -3);
   assert(*(++iter) == -2);
   assert(*(++iter) == -1);
   assert(*(++iter) == 1);
   assert(*(++iter) == 3);
   assert(++iter == list2.end());
   assert(list1.length() == 8);


   list2 = list1.apply(square);
   iter = list2.begin();
   assert(*(iter) == 1);
   assert(*(++iter) == 1);
   assert(*(++iter) == 4);
   assert(*(++iter) == 9);
   assert(*(++iter) == 9);
   assert(*(++iter) == 16);
   assert(*(++iter) == 36);
   assert(*(++iter) == 81);
   assert(++iter == list2.end());
   assert(list1.length() == 8);

   cout << "[OK]" << endl;
}


int main ()
{
   listTest1();
   listTest2();
   listTest3();
   listTest4();
 //  listTest5();
 //  listTest6();
   //listTest7() - strings / ExamDetails
   //listTest8();
   //listTest9();
   //listTest10();
   return 0;
}