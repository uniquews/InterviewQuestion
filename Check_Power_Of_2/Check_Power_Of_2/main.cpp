//
//  main.cpp
//  Check_Power_Of_2
//
//  Created by Shuai Wang on 9/4/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {

public:
    
    bool check (int num) {
    
        if (num == 0) {
            return true;
        }
        
        if (((num - 1) & num) == 0) {
            return true;
        } else {
            return false;
        }
    }


};


int main(int argc, const char * argv[])
{

    Solution su;
    cout << su.check(5) << endl;
    return 0;
}

