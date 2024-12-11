//
//  Date&TimeArithmetic.cpp
//  CIS25
//
//  Created by Merary Murillo on 12/10/24.
//

#include "Date&TimeArithmetic.hpp"

namespace DateTimeArithmetic{


    // Date constructor
    Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

    // Getters for year, month, and day
    int Date::getYear() const { return year; }
    int Date::getMonth() const { return month; }
    int Date::getDay() const { return day; }

    // Time constructor
    Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}


    // Getters for hour, minute, and second
    int Time::getHour() const { return hour; }
    int Time::getMinute() const { return minute; }
    int Time::getSecond() const { return second; }

    DateTime::DateTime(int year, int month, int day, int hour, int min, int sec) : date1(year, month, day), time1(hour, min, sec) {}

    //method to output format
    void DateTime::format() const{
        cout << "Today is " << date1.getYear() << "-" << setw(2) << setfill('0') << date1.getMonth() << "-" << setw(2) << setfill('0') << date1.getDay() << ", and the Time is " << time1.getHour() << ":" << setw(2) << setfill('0') << time1.getMinute() << ":" << setw(2) << setfill('0') << time1.getSecond() << endl;
        
    }
        
        
}

