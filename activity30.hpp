//
//  activity30.hpp
//  CIS25
//
//  Created by Merary Murillo on 11/20/24.
//

#ifndef activity30_hpp
#define activity30_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

namespace Textbox{

class TextBox{
    
    
public:
    //default constructor
    TextBox(){
        value = "";
    };
    
    explicit TextBox(const string& text){  //text is our string object
        
        value = text;   //making sure the class is used properly by making it usable
    }
    
private:
    string value;  //our private string value attribute
};

}


#endif /* activity30_hpp */
