//
//  homework2pt2.hpp
//  CIS25
//
//  Created by Merary Murillo on 12/11/24.
//

#ifndef homework2pt2_hpp
#define homework2pt2_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

namespace AddOns{

class Date{
    
private:
    
    int year;
    int month;
    int day;
    
public:
    
    //Constructor
    Date(int y, int m, int d);
    
    //getters
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    
    // Day of the week using Zeller's Congruence
    int dayOfWeek() const;
    
    int daysOfMonth() const;
    
    //helper to calculate days in a fixed date
    int totalDays() const;
    
};



class Time{
    
private:
    int hour;
    int minute;
    int second;
    
    int timeZoneOffset;
    
    
public:
    
    //constuctor
    Time(int h, int m, int s);
    
    //getters
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    
    //helper to calculate total seconds
    int totalSeconds() const;
    
};


class DateTime {
private:
    Date date1;
    Time time1;
    int timeZoneOffset;  // Store the time zone offset for DateTime

public:
    DateTime(int year, int month, int day, int hour, int min, int sec, int timeOffset = 0);
    void adjustToTimeZone(int newTimeZoneOffset);
    void adjustForDST(bool isDST);
    void format() const;
    string serialize() const;
    static DateTime deserialize(const string& serialized);
    void difference(const DateTime& other) const;
};

}

#endif /* homework2pt2_hpp */
