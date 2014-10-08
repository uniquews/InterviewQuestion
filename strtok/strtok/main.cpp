//
//  main.cpp
//  strtok
//
//  Created by Shuai Wang on 10/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{

    string s = "red blue blue red";
    vector<string> str;
    int start = 0;
    while (start < s.size()) {
        int end = start;
        while (s[end] != ' ') {
            end++;
        }
        
        str.push_back(s.substr(start, end - start + 1));
        start = end + 1;
        
    }
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << endl;
    }
    
    return 0;
}

