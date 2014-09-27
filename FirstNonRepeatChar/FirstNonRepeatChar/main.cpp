//
//  main.cpp
//  FirstNonRepeatChar
//
//  Created by Shuai Wang on 9/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {

public:
    char FirstNonRepeat(char *pString) {
        if (!pString) {
            return '\0';
        }
        
        const int tableSize = 256;
        char *pointer = pString;
        int table[tableSize] = {0};
        while (*pString != '\0') {
            table[*pString]++;
            pString++;
        }
        
        while (*pointer != '\0') {
            if (table[*pointer] == 1) {
                return *pointer;
            } else {
                pointer++;
            }
        }
        
        return '\0';
    
    }

};




int main(int argc, const char * argv[])
{

    char *input = "abaccdeff";
    Solution su;
    cout << su.FirstNonRepeat(input);
    
    
    return 0;
}

