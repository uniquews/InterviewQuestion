//
//  main.cpp
//  LookAndSay
//
//  Created by Shuai Wang on 9/8/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<string> lookAndSay(int n) {
        
        int times = 10;
        char a = (char)(((int)'0') + n);
        vector<string> allResult;
        string result = "";
        string tmp = "";
        tmp += a;
        allResult.push_back(tmp);
        while (times > 0) {
            for (int i = 0; i < tmp.size(); i++) {
                int length = 1;
                while (i + 1 < tmp.size() && tmp[i] == tmp[i + 1]) {
                    length++;
                    i++;
                }
                result += (char)(((int)'0') + length);
                result += tmp[i];
                
                
            }
            tmp = result;
            allResult.push_back(result);
            result = "";
            times--;
            
        }
        
        return allResult;
        
        
    }
    
};

int main(int argc, const char * argv[])
{
    int n = 1;
    Solution su;
    vector<string> result = su.lookAndSay(n);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    
    
    return 0;
}

