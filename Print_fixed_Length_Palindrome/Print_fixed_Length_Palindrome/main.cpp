//
//  main.cpp
//  Print_fixed_Length_Palindrome
//
//  Created by Shuai Wang on 9/8/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    
    vector<string> printPalin(string str) {
        vector<string> result;
        if (str.size() == 0) {
            return vector<string> {};
        } else {
            vector<vector<bool>> f(str.size(), vector<bool> (str.size()));
            for (int i = 0; i < str.size(); i++) {
                f[i][i] = true; // each letter is palindrome
            }
            
            for (int i = str.size() - 1; i >= 0; i--) {
                for (int j = i + 1; j < str.size(); j++) {
                    if (str[i] == str[j] && (j - i < 2 || f[i + 1][j - 1] == true)) {
                        f[i][j] = true;
                        if (j - i + 1 >= 3) {
                            result.push_back(str.substr(i, j - i + 1));
                        }
                        
                    }
                    
                }
            }
            
        }
        
        return result;
        
    }
    
    
};

int main(int argc, const char * argv[])
{

    Solution su;
    string str = "abbcbba";
    vector<string> result =  su.printPalin(str);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

