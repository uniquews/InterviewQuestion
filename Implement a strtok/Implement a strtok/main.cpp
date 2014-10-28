//
//  main.cpp
//  Implement a strtok
//
//  Created by Shuai Wang on 10/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
public:
    vector<string> strtok1(string &str, string &comp) {
        vector<string> result;
        int start = 0;
        while (isToken(str[start], comp)) {
            start++;
        }
        
        int end = start;
        while (end < str.size()) {
            if (isToken(str[end], comp)) {
                string tmp = str.substr(start, end - start);
                result.push_back(tmp);
                while (end < str.size() && isToken(str[end], comp)) {
                    end++;
                }
                start = end;
            } else {
                end++;
            }
        }
        
        return result;
        
    }
    
    bool isToken(char c, string &comp) {
        for (int i = 0; i < comp.size(); i++) {
            if (c == comp[i]) {
                return true;
            }
        }
        
        return false;
    
    }
    
};

int main(int argc, const char * argv[])
{
    
    Solution su;
    string str ="- This, a sample string.";
    string token = " ,.-";
    vector<string> result = su.strtok1(str, token);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

