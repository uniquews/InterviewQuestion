//
//  main.cpp
//  Print Maximun Appear Char
//
//  Created by Shuai Wang on 11/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char print(string &str) {
        vector<int> hashMap(256, 0);
        int resultNum = 0;
        char result = '\0';
        for (int i = 0; i < str.size(); i++) {
            int num = (int)str[i];
            hashMap[num]++;
            if (resultNum < hashMap[num]) {
                resultNum = hashMap[num];
                result = num;
            }
        }
        
        return result;
    }

};

int main(int argc, const char * argv[]) {
    string str = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    Solution su;
    char s = su.print(str);
    cout << s << endl;
    return 0;
}
