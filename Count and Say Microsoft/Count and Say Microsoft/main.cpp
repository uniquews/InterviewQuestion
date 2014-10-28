//
//  main.cpp
//  Count and Say Microsoft
//
//  Created by Shuai Wang on 10/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {

public:
    string countAndSay (string &str) {
        if (str.size() == 0) {
            return "";
        }
        
        string result = "";
        
        int start = 0;
        while (start < str.size()) {
            result += str[start];
            int end = start;
            while (end + 1 < str.size() && str[end] == str[end + 1]) {
                end++;
            }
            
            int len = end - start + 1;
            result.append(to_string(len));
            start = end + 1;
    
        }
        
        return result;
    }

};

int main(int argc, const char * argv[])
{

    string input = "messyyyaaaa";
    Solution su;
    cout << su.countAndSay(input) << endl;
    return 0;
}

