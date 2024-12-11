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
    };



    class Time{
        
    private:
        int hour;
        int minute;
        int second;
        
    public:
        
        //constuctor
        Time(int h, int m, int s);
        
        //getters
        int getHour() const;
        int getMinute() const;
        int getSecond() const;
        
    };


    class DateTime{
        
    private:
        Date date1;
        Time time1;
        
    public:
        
        //constructure to initialize DateTime with Date and Time class
        DateTime(int year, int month, int day, int hour, int min, int sec);
        
        //method to output format
        void format() const;
        
    };

}

#endif /* Date_TimeArithmetic_hpp */
