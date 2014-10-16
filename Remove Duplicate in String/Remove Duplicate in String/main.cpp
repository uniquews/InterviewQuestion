//
//  main.cpp
//  Remove Duplicate in String
//
//  Created by Shuai Wang on 10/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void removeDup (string &str) {
        if (str.size() <= 1) {
            return;
        }
        
        int cur = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[cur] == str[i]) {
                continue;
            } else {
                str[++cur] = str[i];
            }
        }
        
        str.resize(cur + 1);
        return;
        
    }
    
};

int main(int argc, const char * argv[])
{

    string a = "aaaaabbsrgcccccccdefggggg";
    Solution su;
    su.removeDup(a);
    cout << a << endl;
    return 0;
}

