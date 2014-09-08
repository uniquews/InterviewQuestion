//
//  main.cpp
//  Reverse_Bits
//
//  Created by Shuai Wang on 9/4/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {

public:
    
    int reverseBits (int num) {
        
        int result = 0;
        for (int i = 0; i < 8; i++) {
            int tmp = (num >> i) & 1;
            result = (result << 1) + tmp;
        }
        
        return result;
    
    }

};

int main(int argc, const char * argv[])
{

    Solution su;
    cout << su.reverseBits(8) << endl;
    
    return 0;
}

