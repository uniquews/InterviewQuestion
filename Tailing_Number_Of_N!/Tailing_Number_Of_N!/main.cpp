//
//  main.cpp
//  Tailing_Number_Of_N!
//
//  Created by Shuai Wang on 9/4/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    long long tailingZero(int num) {
    
        int base = 5;
        int i = 1;
        long long result = 0;
        while (num / (pow(base, i)) > 0) {
            result += num / pow(base, i);
            i++;
        }
        
        return result;
    }
    
    void check (int num) {
        long long result = 1;
        for (int i = 1; i <= num; i++) {
            result = result * i;
            
        }
        
        cout << result << endl;
        
    }


};

int main(int argc, const char * argv[])
{

    Solution su;
    cout << su.tailingZero(17) << endl;
    su.check(17);
    return 0;
}

