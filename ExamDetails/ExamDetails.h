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
         * @exception InvalidDateException if date is invalid
         * @exception InvalidTimeException if time is invalid
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
        /**
         * @brief returns the amount of days between 2 exams
         * 
         * @param exam - the exam to compare with
         * @return int - numbers of days between the 2 exams
         */
        int operator-(const ExamDetails& exam) const;
        /**
         * @brief check if the left exam's date is before the second exam's date 
         * 
         * @param exam -  the exam to compare with
         * @return true - if the left exam's date is before the second exam's date 
         * @return false - if the left exam's date is after the second exam's date 
         */
        bool operator<(const ExamDetails& exam) const; 
        /**
         * @brief prints the details of the exam
         * 
         * @param os the output channal
         * @param exam the exam who will be printed
         * @return std::ostream& 
         */
        friend std::ostream& operator<<(std::ostream& os, const ExamDetails& exam);
        /**
         * @brief builds a new defoult exam
         * 
         * @return ExamDetails object
         */
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