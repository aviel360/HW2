#include <iostream>
#include "ExamDetails.h"

#define DAYS_IN_MONTH 30
#define HALF_HOUR 3
#define ROUND_HOUR 0

namespace mtm{
    ExamDetails::ExamDetails(int course, int month, int day, double hour, int length, std::string link) :
                    course(course), month(month), day(day), hour(hour), length(length), link(link){}

    std::string ExamDetails::getLink() const{
        return this->link;
    }
    
    void ExamDetails::setLink(std::string link){
        this->link = link;
    }

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
        int time = exam.hour > (int)exam.hour ? HALF_HOUR : ROUND_HOUR; 
        os << "Course Number: " << exam.course << std::endl 
        << "Time: " << exam.day << "." << exam.month << " at " << (int)exam.hour << ":" << time << "0" << std::endl
        << "Duration: " << exam.length << ":00" << std::endl
        << "Zoom Link: " << exam.link;
        return os;
    }

    ExamDetails ExamDetails::makeMatamExam(){
        ExamDetails matam(234124,7,28,13,3,"https:///tinyurl.com/59hzps6m");
        return matam;
    }
}

