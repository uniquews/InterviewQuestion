//
//  main.cpp
//  Match String
//
//  Created by Shuai Wang on 11/4/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:
    
    bool match(string &pattern, string &str) {
        vector<string> tokens = split(str);
        unordered_map<char, string> patternMap;
        unordered_map<string, char> wordMap;
        
        if (pattern.size() != tokens.size()) {
            return false;
        }
        
        for (int i = 0; i < tokens.size(); i++) {
            if (patternMap.find(pattern[i]) == patternMap.end() && wordMap.find(tokens[i]) == wordMap.end()) {
                patternMap[pattern[i]] = tokens[i];
                wordMap[tokens[i]] = pattern[i];
            } else if (patternMap.find(pattern[i]) != patternMap.end() && wordMap.find(tokens[i]) != wordMap.end()) {
                if (patternMap[pattern[i]] == tokens[i] && wordMap[tokens[i]] == pattern[i]) {
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
    
    
    vector<string> split (string &str) {
        vector<string> tokens;
        int start = 0;
        while (start < str.size()) {
            int end = start;
            while (end < str.size() && str[end] != ' ') {
                end++;
            }
            
            tokens.push_back(str.substr(start, end - start));
            start = end + 1;
        
        }
        return tokens;
    }

    
};

int main(int argc, const char * argv[]) {
//    string pattern = "abba";
//    string str = "red blue blue red";
//    string str = "red blue yellow red";
//    string pattern = "aaaa";
//    string str = "red red red red";
      string pattern = "abba";
    string str = "red red red red";
    Solution su;
//    vector<string> result = su.split(str);
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i] << endl;
//    }
    
    cout << su.match(pattern, str) << endl;
    return 0;
}
