#include <iostream>
#include <cmath> 
#include "ExamDetails.h"
#include "SortedList.h"

#define DAYS_IN_MONTH 30
#define HALF_HOUR 3
#define ROUND_HOUR 0
#define COURSE 234124
#define MONTH 7
#define DAY 28
#define TIME 13
#define LENGTH 3
#define LINK "https://tinyurl.com/59hzps6m"
#define MAX_MONTH 12
#define MAX_DAY 30
#define HOURS_IN_DAY 24
#define HALF 0.5

using std::endl;
using std::string;
namespace mtm{
    ExamDetails::ExamDetails(int course, int month, int day, double hour, int length, string link) :
                    course(course), month(month), day(day), hour(hour), length(length), link(link){
        if(!isDateValid(month, day)){
            throw InvalidDateException();
        }
        if(!isTimeValid(hour) || length <= 0){
            throw InvalidTimeException();
        }
    }
    
    string ExamDetails::getLink() const{
        return this->link;
    }
    
    void ExamDetails::setLink(string link){ this->link = link; }

    int ExamDetails::operator-(const ExamDetails& exam) const{
        int difference = this->month - exam.month;
        return this->day - exam.day + difference*DAYS_IN_MONTH;
    }

    bool ExamDetails::operator<(const ExamDetails& exam) const{
        if(*this - exam < 0){
            return true;
        }
        else if(*this - exam > 0){
            return false;
        }
        else{
            return this->hour < exam.hour ? true : false;
        }
    }

    std::ostream& operator<<(std::ostream& os, const ExamDetails& exam){
        int time = exam.hour > static_cast<int>(exam.hour) ? HALF_HOUR : ROUND_HOUR; 
        os << "Course Number: " << exam.course << endl 
        << "Time: "<< exam.day << "." << exam.month <<" at "<< static_cast<int>(exam.hour) << ":" <<time<< "0" << endl
        << "Duration: " << exam.length << ":00" << endl
        << "Zoom Link: " << exam.link << endl;
        return os;
    }

    ExamDetails ExamDetails::makeMatamExam(){
        ExamDetails matam(COURSE,MONTH,DAY,TIME,LENGTH,LINK);
        return matam;
    }

    bool isDateValid(int month, int day){
        return (month > 0 && month <= MAX_MONTH) || (day > 0 && day <= MAX_DAY);
    }

    bool isTimeValid(double hour){
        int max_time = HOURS_IN_DAY;
        while(hour > 0 && max_time > 0){
            hour -= 1;
            max_time--;
        }
        return hour == 0 || hour + HALF == 0 ;
    }

}
