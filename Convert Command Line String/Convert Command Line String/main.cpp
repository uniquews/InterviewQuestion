//
//  main.cpp
//  Convert Command Line String
//
//  Created by Shuai Wang on 10/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string input) {
        string result = "";
        bool isValid = false;
        int len  = (int)input.size();
        int i = 0;
        while (i < len) {
            if (input[i] == '"') {
                int start = i;
                int end = ++i;
                while (end < len && input[end] != '\"') {
                    end++;
                }
                string tmp = input.substr(start, end - start + 1);
                result.append(tmp).append(",");
                
                i = end;
            } else if (input[i] >= '1' && input[i] <= '9') {
                int start = i;
                int end = i;
                while (input[end] != ' ') {
                    end++;
                }
                string tmp = input.substr(start, end - start);
                result.append("\"").append(tmp).append("\"").append(",");
                i = end;
            }
            i++;
        }
        
        result.resize(result.size() - 1);
        
        return result;
    }
    
    
};

int main(int argc, const char * argv[])
{

    string input = "12 \"23 4\" 456 78 \"2 35\"";
    Solution su;
    string result = su.convert(input);
    
    cout << result << endl;
    return 0;
}

