//
//  main.cpp
//  Serilization
//
//  Created by Shuai Wang on 10/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string serilization (vector<string> &A) {
        
        string result = "";
        string display = "";
        for (auto a : A) {
            for (auto c : a) {
                int num = c;
                display.append(string(1, c));
                result.append(to_string(num)).append("+");
            }
            result.append("*");
            display.append(" ");
            
        }
        display.resize(display.size() - 1);
        cout << "Serilization Display: "<< display << endl;

        return result;
    }
    
    vector<string> deserilization(string &str) {
        vector<string> v;
        int start = 0;
        string eachItem = "";
        while (start < (int)str.size()) {
            
            int end = start;
            while (str[end] != '+' && str[end] != '*' && end < (int)str.size()) {
                end++;
            }
            
            if (str[end] == '+') {
                string tmp = str.substr(start, end - start);
                int num = stoi(tmp);
                char c = (num);
                string s(1, c);
                eachItem.append(s);
                start = end + 1;
            } else if (str[end] == '*') {
                v.push_back(eachItem);
                eachItem.clear();
                start = end + 1;
            } else {
                start = end;
            }
            
            
        }
        
        return v;
    }


};

int main(int argc, const char * argv[]) {
    vector<string> v = {"abc", "bgf", "123", "*#*", "*#+ehgesh 39"};
   
    Solution su;
    string result = su.serilization(v);
//    cout << "Result: "<< result << endl;
        vector<string> final = su.deserilization(result);
    cout << "Deserilization: " << endl;
    for (int i = 0; i < final.size(); i++) {
        cout << final[i] << endl;
    }
    return 0;
}
