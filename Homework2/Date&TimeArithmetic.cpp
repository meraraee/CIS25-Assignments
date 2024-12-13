//
//  Date&TimeArithmetic.cpp
//  CIS25
//
//  Created by Merary Murillo on 12/10/24.
//

#include "Date&TimeArithmetic.hpp"
#include <iostream>
 
using namespace std;

namespace DateTimeArithmetic{


    // Getter implementations for the DateTime base class
    int DateTime::getYear() const {
        return year;
    }

    int DateTime::getMonth() const {
        return month;
    }

    int DateTime::getDay() const {
        return day;
    }

    int DateTime::getHour() const {
        return hour;
    }

    int DateTime::getMinute() const {
        return minute;
    }

    int DateTime::getSecond() const {
        return second;
    }

}


