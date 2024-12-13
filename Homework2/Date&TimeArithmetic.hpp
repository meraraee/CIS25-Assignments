//
//  Date&TimeArithmetic.hpp
//  CIS25
//
//  Created by Merary Murillo on 12/10/24.
//

#ifndef Date_TimeArithmetic_hpp
#define Date_TimeArithmetic_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

namespace DateTimeArithmetic{


// base class
class DateTime{
 
//to only allow derived classes to have access
protected:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
        
public:
    
    DateTime(int y, int m, int d, int h, int min, int sec)  : year(y), month(m), day(d), hour(h), minute(min), second(sec){}
    
    //getters
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    
    //helper to calculate days in a fixed date
    int totalDays() const{
        
        return year * 365 + (month - 1) * 30 + day;
    }
    
    //helper to calculate total seconds
    int totalSeconds() const{
        return (hour * 3600) + (minute * 60) + second;
    }
    
    // Method to output DateTime in desired format
        void format() const {
            cout << getYear() << "-" << setw(2) << setfill('0') << getMonth() << "-" << setw(2) << setfill('0') << getDay()
                    << ", and the Time is " << getHour() << ":" << setw(2) << setfill('0') << getMinute()
                    << ":" << setw(2) << setfill('0') << getSecond();
            }

    // Method to calculate the difference between 2 DateTime objects
        void difference(const DateTime& other) const {
            int daysDiff = totalDays() - other.totalDays();
            int timeDiff = totalSeconds() - other.totalSeconds();

    // Calculating the total difference in days, hours, minutes, and seconds
        int hours = timeDiff / 3600;
        timeDiff %= 3600;
        int minutes = timeDiff / 60;
        int seconds = timeDiff % 60;

    // in case if the time difference is negative
        if (timeDiff < 0) {
            hours = -hours;
            minutes = -minutes;
            seconds = -seconds;
            daysDiff -= 1;
        }

    // Calculating the difference in months
        int months = 0;
        months += (getYear() - other.getYear()) * 12;
        months += getMonth() - other.getMonth();
            
            if (getDay() < other.getDay()) {
                months -= 1;
            }

    // Outputting the difference
        cout << "Difference: " << months << " months, " << daysDiff << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." << endl;
            }
    
    };


class Date: public DateTime{
    
public:
    
    // Constructor for Date
    Date(int y, int m, int d) : DateTime(y, m, d, 0, 0, 0) {}
    
    // Method to output only the date part
    void format() const {
        cout << getYear() << "-" << setw(2) << setfill('0') << getMonth() << "-" << setw(2) << setfill('0') << getDay();
    }
    
};



    class Time: public DateTime{
        
   
    public:
        
    // Constructor for Time
    Time(int h, int mi, int s) : DateTime(0, 0, 0, h, mi, s) {}

    // Method to output only the time part
    void format() const {
     cout << getHour() << ":" << setw(2) << setfill('0') << getMinute() << ":" << setw(2) << setfill('0') << getSecond();
    }
};

}

#endif /* Date_TimeArithmetic_hpp */
