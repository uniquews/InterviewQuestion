//
//  main.cpp
//  Rotate_String
//
//  Created by Shuai Wang on 8/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string> 
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool isRoated(string a, string b) {
        
        if (a == "" && b == "") {
            return true;
        }
        
        if (a == "" || b == "") {
            return false;
        }
    
        unordered_set<string> rotation;
        rotation.insert(a);
        Rotation(a,rotation);
        
        if (rotation.find(b) != rotation.end()) {
            return true;
        }
        
        return false;
    }
    
    void Rotation(string str, unordered_set<string> &rotation) {
        for (int i = 1; i < str.size(); i++) {
            string subString = str.substr(0, i);
            string remainString = str.substr(i, str.size() - i);
            remainString.append(subString);
            rotation.insert(remainString);
        }
        
        return;
    }
    
};

int main(int argc, const char * argv[])
{

//    string a = "abc";
//    string b = "bac";
//    string b = "bca";
    
//    string a = "";
//    string b = "";
    
//    string a = "";
//    string b ="ajgsoign";
    
    
//    string a = "aaabcc";
//    string b ="abccaa";
    
//    string a = "ab";
//    string b = "bc";
    
    string a = "odeleetc";
    string b = "codeleet";

    
    
    
    Solution su;
    cout <<  su.isRoated(a, b) << endl;
    return 0;
}

