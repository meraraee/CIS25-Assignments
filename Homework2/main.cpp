//
//  main.cpp
//  CIS25
//
//  Created by Merary Murillo on 12/10/24.
//

#include <stdio.h>
#include "Date&TimeArithmetic.hpp"

#include <iostream>

using namespace std;

using namespace DateTimeArithmetic;

int main(){

    // Create Date objects for date and Time objects for time.
    Date date1(2024, 12, 11);
    Time time1(12, 15, 45);
    Date date2(2024, 06, 27);
    Time time2(07, 00, 20);

    // Outputting the format for Date and Time objects
    cout << "DateTime 1: ";
    date1.format();
    cout << ", ";
    time1.format();
    cout << endl;
    
    cout << "DateTime 2: ";
    date2.format();
    cout << ", ";
    time2.format();
    cout << endl;

    // Output the difference between DateTime 1 and DateTime 2
    DateTime diff1(date1.getYear(), date1.getMonth(), date1.getDay(), time1.getHour(), time1.getMinute(), time1.getSecond());
    DateTime diff2(date2.getYear(), date2.getMonth(), date2.getDay(), time2.getHour(), time2.getMinute(), time2.getSecond());

    diff1.difference(diff2);
    
    
    return 0;
}
