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
        /**
         * @brief Construct a new Exam Details object
         * 
         * @param course - an integer
         * @param month - an integer between 1 to 12
         * @param day  -  an integer between 1 to 30
         * @param hour - time in exactly halfs of an hour
         * @param length - a positive integer
         * @param link  - string with the link to the exam 
         */
        ExamDetails(int course, int month, int day, double hour, int length, std::string link = "");
        /**
         * @brief Construct a new Exam Details object
         * 
         */
        ExamDetails() = default;
        /**
         * @brief Destroy the Exam Details object
         * 
         */
        ~ExamDetails() = default;
        /**
         * @brief Construct a new Exam Details object
         * 
         * @param exam 
         */
        ExamDetails(const ExamDetails& exam) = default;
        /**
         * @brief assignment operator
         * 
         * @return ExamDetails& 
         */
        ExamDetails& operator=(const ExamDetails&) = default;
        /**
         * @brief Get the Link object
         * 
         * @return string with the link to the exam  
         */
        std::string getLink() const;
        /**
         * @brief Set the Link object
         * 
         * @param link string with the link to the exam
         */
        void setLink(std::string link);
        
        int operator-(const ExamDetails& exam) const;
        bool operator<(const ExamDetails& exam) const; 
        friend std::ostream& operator<<(std::ostream& os, const ExamDetails& exam);
        static ExamDetails makeMatamExam();
        class InvalidDateException : public std::exception{};
        class InvalidTimeException : public std::exception{};
        class InvalidArgsException : public std::exception{};

    };
    
    /**
     * @brief returns if the date is a valid date 
     * 
     * @param month 
     * @param day 
     * @return true - if month is between 1 to 12, day is between 1 to 30 
     * @return false - if is out of this range
     */
    bool isDateValid(int month, int day);
    /**
     * @brief returns if the Time is in exactly halfs of an hour
     * 
     * @param hour 
     * @return true - if the time in exactly halfs of an hour
     * @return false if the time is out of this range
     */
    bool isTimeValid(double hour);
}

#endif