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
    
    //created DateTime object & intializing date and time
    DateTime dateTime1(2024, 12, 11, 12, 15, 45);
    
    //outputting format
    dateTime1.format();
    
    
    return 0;
}
