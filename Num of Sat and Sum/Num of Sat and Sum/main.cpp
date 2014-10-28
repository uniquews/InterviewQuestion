//
//  main.cpp
//  Num of Sat and Sum
//
//  Created by Shuai Wang on 10/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    
    int numofSatAndSum (int startDay, int totalDays) {
        int weeks1 = totalDays / 7;
        
        int remainingDays = totalDays % 7;
        
        int week2 = (startDay + remainingDays) / 7;
        
        int result = (weeks1 + week2) * 2;
        
        return result;
    }


};

int main(int argc, const char * argv[])
{

    Solution su;
//    int startDay = 1;
//    int totalDays = 14;
//    cout << su.numofSatAndSum(startDay, totalDays) << endl;
    
    int startDay = 4;
    int totalDays = 20;
    cout << su.numofSatAndSum(startDay, totalDays) << endl;
    return 0;
}

