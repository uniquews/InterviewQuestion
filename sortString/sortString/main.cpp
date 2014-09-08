//
//  main.cpp
//  sortString
//
//  Created by Shuai Wang on 9/5/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {


public:
    vector<string> sortStringInGivenNum(int num) {
        vector<string> result;
        int k = 0;
        string str = "";
       
        dfs (num, result, k, str, 0);

        return result;
    }
    
    void dfs(int num, vector<string> &result, int k, string &str, char c) {
        if (k == num) {
            result.push_back(str);
            return;
        }
        
        if (c == 0) {
            for (char tmp = 'a'; tmp <= 'z'; tmp++) {
                string str = "";
                string tmpStr = str;
                str += tmp;
                dfs(num, result, 1, str, tmp + 1);
                str = tmpStr;
                str += tmp - 32;
                dfs(num, result, 1, str, tmp + 1);
                
            }
            
            
        } else {
            for (char tmp= c; tmp <= 'z'; tmp++) {
                string tmpStr = str;
                str += tmp;
                dfs(num, result, k + 1, str, tmp + 1);
                str = tmpStr;
                str += tmp - 32;
                dfs(num, result, k + 1, str, tmp + 32 - 1);
                str = tmpStr;
                
            }
        
        }
    
    }
    
};

int main(int argc, const char * argv[])
{

    int k = 2;
    Solution su;
    vector<string> result = su.sortStringInGivenNum(k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    
    }
    

    cout <<  endl;
    return 0;
}

