//
//  main.cpp
//  Similar_Word
//
//  Created by Shuai Wang on 9/13/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    
    bool similarWord(string str1, string str2) {
        int i = 0;
        int j = 0;
        int numOfDiff = 0;
        while (i < str1.size() || j < str2.size()) {
            if (i == str1.size()) {
                numOfDiff += str2.size() - j;
                break;
            }
            
            if (j == str2.size()) {
                numOfDiff += str1.size() - i;
                break;
            }
            
            if (str1[i] == str2[j]) {
                i++;
                j++;
            } else if (j + 1 < str2.size() && str1[i] == str2[j + 1]) {
                j++;
                numOfDiff++;
            } else if (i + 1 < str1.size() && str1[i + 1] == str2[j]) {
                i++;
                numOfDiff++;
            } else {
                i++;
                j++;
                numOfDiff += 2;
            }
        
        }
        
        if (numOfDiff == 2) {
            return true;
        } else {
            return false;
        }
    
    }

};

int main(int argc, const char * argv[])
{
    string str1 = "healow";
    string str2 = "hmello";
    
    string str4 = "b";
    string str3 = "e";
    Solution su;
    cout << su.similarWord(str1, str2) << endl;
    cout << su.similarWord(str3, str4) << endl;
    
    
}

