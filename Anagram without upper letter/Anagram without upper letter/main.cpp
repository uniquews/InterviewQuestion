//
//  main.cpp
//  Anagram without upper letter
//
//  Created by Shuai Wang on 9/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> Anagram(string s) {
        if (s.size() == 0) {
            return vector<string> {};
        }
        
        string str = s;
        
        unordered_map<int, char> upperLetter;
        for (int i = 0; i < s.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                upperLetter[i] = str[i];
                str.erase(i, 1);
            }
        }
        
        string eachResult = "";
        vector<string> result;
        vector<string> finalResult;
        unordered_map<int, bool> visited;
        dfs(s, 0, eachResult, result, visited);
        
        
        for (int i = 0; i < result.size(); i++) {
            string tmp = result[i];
            string newStr = "";
            for (int j = 0; j < tmp.size(); j++) {
                if (upperLetter.find(j) != upperLetter.end()) {
                    newStr += upperLetter[j];
                } else {
                    newStr += tmp[j];
                }
            }
            
            finalResult.push_back(newStr);
            
        }
        
        return finalResult;
        
        
    }
    
    void dfs(string s, int step, string eachResult, vector<string> &result, unordered_map<int, bool> &visited) {
        if (step == s.size()) {
            result.push_back(eachResult);
            return;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (visited.find(i) == visited.end() || visited[i] == false) {
                visited[i] = true;
                eachResult.append(s.substr(i, 1));
                dfs(s, step + 1, eachResult, result, visited);
                eachResult.resize(s.size() - 1);
                visited[i] = false;
            }
        }
        
        return;
        
    }
    
    
};


int main(int argc, const char * argv[])
{

    Solution su;
    string a = "POPa";
    vector<string> result = su.Anagram(a);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

