//
//  main.cpp
//  Match String Follow up Dropbox
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
    
    
    vector<vector<string>> generateTokens(string &pattern, string &str) {
        int numOfSpace = (int)pattern.size() - 1;
        
        vector<string> eachResult;
        vector<vector<string>> result;
        dfs(str, 0, numOfSpace, numOfSpace, eachResult, result);
        return result;
    
    }

    void dfs(string &str, int index, int parts, int cut, vector<string> &eachResult, vector<vector<string>> &result) {
        
        if (index >= str.size()) {
            return;
        }
        if (parts == 0) {
            string tmp = str.substr(index);
            eachResult.push_back(tmp);
            result.push_back(eachResult);
            eachResult.pop_back();
            return;
        }
        
        
        for (int i = 1; str.size() - i >= parts; i++) {
            string tmp = str.substr(index, i);
            eachResult.push_back(tmp);
            dfs(str, index + i, parts - 1, cut, eachResult, result);
            eachResult.pop_back();
        }
        
        return;
    }
    
    
    bool callMatch(string &str, string &pattern) {
        vector<vector<string>> allTokens = generateTokens(pattern, str);
        for (int i = 0; i < allTokens.size(); i++) {
            vector<string> eachTokens = allTokens[i];
            
            if (match(pattern,eachTokens)) {
                return true;
            }
        
        }
        
        return false;
    
    }
    
    bool match(string &pattern, vector<string> &tokens) {

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
};

int main(int argc, const char * argv[]) {
    string pattern = "abba";
//    string str = "redbluebluered";
    string str = "redblueyellowred";
    
//    string pattern = "aaaa";
//    string str = "redredredred";
    
    Solution su;
    vector<vector<string>> result = su.generateTokens(pattern, str);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] <<  " ";
        }
        
        cout << endl;
    }
    
    
    cout << su.callMatch(str, pattern) << endl;;
    return 0;
}
