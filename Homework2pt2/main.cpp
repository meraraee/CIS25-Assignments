//
//  main.cpp
//  CIS25
//
//  Created by Merary Murillo on 12/11/24.
//

#include <stdio.h>
#include "homework2pt2.hpp"

#include <iostream>

using namespace std;

using namespace AddOns;

int main(){
    
    // DateTime objects with initial values
    DateTime dateTime1(2024, 12, 11, 12, 15, 45);  // UTC+0
    DateTime dateTime2(2024, 06, 27, 07, 00, 20);  // UTC+0

    // Output the difference between the two DateTime objects (only this output is needed)
    dateTime1.difference(dateTime2);  // This will print the difference once.
    
    // Adjust for time zone change (UTC+3)
    dateTime1.adjustToTimeZone(3);  // Adjusting to UTC+3
    dateTime1.format();  // Only printing the final adjusted time
    
    // Adjust for daylight saving time (DST), assuming you want to show it here.
    dateTime1.adjustForDST(true);  // Adjust for DST (adds 1 hour)
    dateTime1.format();  // Show adjusted time after DST change

    // Serialize and Deserialize the DateTime object
    string serialized = dateTime1.serialize();  // Serialize the DateTime object
    cout << "Serialized: " << serialized << endl;  // Print serialized form

    DateTime deserialized = DateTime::deserialize(serialized);  // Deserialize back
    deserialized.format();  // Print the deserialized DateTime object (in UTC+0)

    
    return 0;
}
