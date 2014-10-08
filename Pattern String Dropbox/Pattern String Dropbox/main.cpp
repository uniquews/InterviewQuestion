//
//  main.cpp
//  Pattern String Dropbox
//
//  Created by Shuai Wang on 10/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool valid(string pattern, string s) {
        if (pattern.size() == 0 && s.size() == 0) {
            return true;
        }
        
        if (pattern.size() == 0 || s.size() == 0) {
            return false;
        }
        
        
        vector<string> str;
        split(s, str);
        
        if (pattern.size() != str.size()) {
            return false;
        }
        
        unordered_map<char, string> hashMap;
        unordered_map<string, char> hashMap2;
        for (int i = 0; i < pattern.size(); i++) {
            if (hashMap.find(pattern[i]) == hashMap.end() && hashMap2.find(str[i]) == hashMap2.end()) {
                hashMap[pattern[i]] = str[i];
                hashMap2[str[i]] = pattern[i];
                
            } else if (hashMap.find(pattern[i]) != hashMap.end() && hashMap2.find(str[i]) != hashMap2.end()) {
                if (hashMap[pattern[i]] == str[i] && hashMap2[str[i]] == pattern[i]) {
                    continue;
                } else {
                    return false;
                }
            } else {
                return false;
            }
            
            
        }
        
        return true;
    }
    
    
    
    void split(string s, vector<string> &str) {
        
        int start = 0;
        while (start < s.size()) {
            int end = start;
            while (s[end] != ' ' && end < s.size()) {
                end++;
            }
            
            if (end == s.size()) {
                str.push_back(s.substr(start, end - start + 1));
            } else {
                str.push_back(s.substr(start, end - start));
            }
            
            start = end + 1;
            
        }
        return;
    }
    
    
    
};

int main(int argc, const char * argv[])
{

    string pattern = "abba";
    string pattern2 = "aaaa";
    string s = "red blue blue red";
    string s2 = "red red red red";
    string s3 = "red blue yellow red";
    
    Solution su;
    cout << su.valid(pattern2, s2) <<endl;
    return 0;
}

