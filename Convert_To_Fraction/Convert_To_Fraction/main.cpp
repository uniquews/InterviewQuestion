//
//  main.cpp
//  Convert_To_Fraction
//
//  Created by Shuai Wang on 9/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    vector<int> convertFraction(double num) {
        if (num == 0) {
            return vector<int> {};
        }
        
        vector<int> result;
        int low = 10000;
        int high = num * 10000;
        
        int divisor = getDivisor(low, high);
        
        if (divisor == 1) {
            result.push_back(high);
            result.push_back(low);
        } else {
            result.push_back(high / divisor);
            result.push_back(low / divisor);
        }
        
        return result;
        
    }
    
    
    int getDivisor(int low, int high) {
        
        int c;
        
        while (high != 0) {
            c = low % high;
            low = high;
            high = c;
        }
        
         return low;
    }

    
   
};

int main(int argc, const char * argv[])
{

    Solution su;
    double num = 0.3;
    vector<int> result = su.convertFraction(num);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

