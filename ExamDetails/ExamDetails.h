#ifndef EXAMDETAILS_H
#define EXAMDETAILS_H
#include <iostream>

namespace mtm{
    class ExamDetails {
        int course;
        int month;
        int day;
        double hour;
        double length;
        std::string link;
        
    public:
        ExamDetails(int course, int month, int day, double hour, double length, std::string link = "");
        ExamDetails() = default;
        ~ExamDetails() = default;
        ExamDetails(const ExamDetails& exam) = default;
        ExamDetails& operator=(const ExamDetails&) = default;
        std::string getLink() const;
        void setLink(std::string link);
        int operator-(const ExamDetails& exam) const;
        bool operator<(const ExamDetails& exam) const; 
        friend std::ostream& operator<<(std::ostream& os, const ExamDetails& exam);
        static ExamDetails makeMatamExam();
        class InvalidDateException : public std::exception{};
        class InvalidTimeException : public std::exception{};
        class InvalidArgsException : public std::exception{};
    };
    
    bool isDateValid(int month, int day);
    bool isTimeValid(double hour);
    bool isLengthValid(double length);
}

#endif