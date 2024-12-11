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

    //a helper to calculate the total number of days from a fixed date
    int Date::totalDays() const {
        
        int totalDays = year * 365 + (month - 1) * 30 + day;
        
        return totalDays;
    }

    // Time constructor
    Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}


    // Getters for hour, minute, and second
    int Time::getHour() const { return hour; }
    int Time::getMinute() const { return minute; }
    int Time::getSecond() const { return second; }

    //helper to calcuate seconds
    int Time::totalSeconds() const{
    
        return (hour * 3600) + (minute + 60) + second;
    }

    DateTime::DateTime(int year, int month, int day, int hour, int min, int sec) : date1(year, month, day), time1(hour, min, sec) {}

    //method to output format
    void DateTime::format() const{
        cout << "Today is " << date1.getYear() << "-" << setw(2) << setfill('0') << date1.getMonth() << "-" << setw(2) << setfill('0') << date1.getDay() << ", and the Time is " << time1.getHour() << ":" << setw(2) << setfill('0') << time1.getMinute() << ":" << setw(2) << setfill('0') << time1.getSecond() << endl;
        
    }
        
    //method to calculate the difference between 2 objects of DateTime
    void DateTime::difference( const DateTime& other) const{
    
        int daysDiff = date1.totalDays() - other.date1.totalDays();
        int timeDiff = time1.totalSeconds() - other.time1.totalSeconds();
        
        //calculating the total difference in days, hours, minutes, and seconds
        int hours = timeDiff / 3600;
        timeDiff %= 3600;
        int minutes = timeDiff / 60;
        int seconds = timeDiff % 60;

        //adjust if the time difference is negative
        if (timeDiff < 0) {
            hours = -hours;
            minutes = -minutes;
            seconds = -seconds;
            daysDiff -= 1;
        }
        
        //calcuating the difference in months
        int months = 0;
        months += (date1.getYear() - other.date1.getYear()) * 12;
        months += date1.getMonth() - other.date1.getMonth();
        
        if(date1.getDay() < other.date1.getDay()){
            months -= 1;
    
        }
        
        //outputtinb the difference
        cout << "Difference: " << months << " months, " << daysDiff << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." << endl;
        
    }
        
}

