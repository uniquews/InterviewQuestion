//
//  main.cpp
//  Print_Numbers
//
//  Created by Shuai Wang on 9/8/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> printNumbers(int n) {
        if (n == 0) {
            return vector<string> {};
        }
        
        vector<string> result;
        string str = "";
        
        
        dfs(result, str, 0, n, 1);
        
        return result;
        
    }
    
    void dfs(vector<string> &result, string &str, int length, int n, int number) {
        if (length == n) {
            result.push_back(str);
            return;
        }
        
        
        for (int i = number; i <= 9; i++) {
            string tmp = str;
            str += (((int)'0') + i);
            length++;
            dfs(result, str, length, n, i + 1);
            str = tmp;
            length--;
        }
        
        return;
        
    }
    
    
    
};

int main(int argc, const char * argv[])
{

    Solution su;
    vector<string> result = su.printNumbers(3);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

