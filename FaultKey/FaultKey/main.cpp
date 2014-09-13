//
//  main.cpp
//  FaultKey
//
//  Created by Shuai Wang on 9/8/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool check(string enter, string expect) {
        if (enter.size() == 0) {
            return false;
        }
        
        char faultKey = '\0';
        int i = 0;
        int j = 0;
        for ( ;i < expect.size() && j < enter.size(); i++) {
            if (enter[j] == expect[i]) {
                j++;
            } else {
                if (faultKey == '\0') {
                    faultKey = expect[i];
                } else {
                    
                    if (expect[i] == faultKey) {
                        continue;
                    } else {
                        return false;
                    }
                    
                }
                
            }
        }
        
        if (i == expect.size() && j == enter.size()) {
            return true;
        } else {
            return false;
        }
        
    }
    
    
};

int main(int argc, const char * argv[])
{

    Solution su;
    string enter = "16684";
    string expect = "18684";
    cout << su.check(enter, expect) << endl;
    return 0;
}

