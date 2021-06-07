#include <iostream>
#include "ExamDetails.h"

using namespace mtm;
using namespace std;

int main() {
    ExamDetails exam1 = ExamDetails::makeMatamExam();
    ExamDetails exam2(104032, 7, 11, 9.5, 3);
    ExamDetails exam3 = exam1;

    std::cout << "the differene between MATAM and info 2m is " << (exam1 - exam2) << " days" << std::endl;

    ExamDetails& closest = (exam1 < exam2) ? exam1 : exam2;
    std::cout << "Your closest exam is:" << std::endl << closest << std::endl;

    cout << exam3 << endl << endl << exam1;
}
