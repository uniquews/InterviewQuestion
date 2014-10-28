//
//  main.cpp
//  Add two numbers without using arithmetic operators
//
//  Created by Shuai Wang on 10/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int Add(int x, int y)
    {
        //x 和 y相加 或 不进位加法的结果和进位相加
        while (y != 0)
        {
            // x 和 y 做加法会不会产生进位，
            int carry = x & y;
            
            // x 和 y 做 不进位加法 赋值给x  等着下一轮和y相加
            x = x ^ y;
            
            // 进位要向右移1位(因为是进位，要移到下一位) 附给y  等着下一轮和x相加
            y = carry << 1;
        }
        return x;
    }

};

int main(int argc, const char * argv[])
{

    int a = 6;
    int b = 7;
    Solution su;
    cout << su.Add(a, b) <<endl;
    return 0;
}

