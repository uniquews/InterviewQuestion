//
//  main.cpp
//  itoa
//
//  Created by Shuai Wang on 10/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string itoa(int number) {
        int division = 1;
        string result = "";
        if (number < 0) {
            result += '-';
        }
        
        number  = abs(number);
        
        while (number / division >= 10) {
            division = division * 10;
        }
        
        while (division > 0) {
            int digit = number / division;
            result += digit + '0';
            number = number % division;
            division /= 10;
            
        }
        
        return result;
        
    }
    
};

int main(int argc, const char * argv[])
{

    int number = -0;
    Solution su;
    cout << su.itoa(number) << endl;
    return 0;
}

