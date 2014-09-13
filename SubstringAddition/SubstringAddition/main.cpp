//
//  main.cpp
//  SubstringAddition
//
//  Created by Shuai Wang on 9/8/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
 
    
    vector<vector<int>> substrAdd (vector<int> &num, int target) {
        
        if (num.size() == 0) {
            return vector<vector<int>> {};
        }
        
        
        
        vector<vector<int>> result;
        
        int prevSum = 0;
        vector<int> sum;
        sum.push_back(0);
        for (int i = 0; i < num.size(); i++) {
            prevSum = prevSum + num[i];
            sum.push_back(prevSum);
        }
        
        for (int i = 0; i < sum.size() - 1; i++) {
            for (int j = i + 1; j < sum.size(); j++) {
                if (sum[j] - sum[i] ==target) {
                    int start = i;
                    vector<int> eachResult;
                    while (start < j) {
                        eachResult.push_back(num[start]);
                        start++;
                    }
                    
                    result.push_back(eachResult);
                }
            }
            
        }
        
        return result;
        
    }
    
    
};

int main(int argc, const char * argv[])
{

    
    Solution su;
    vector<int> num = {1, 7, 6, 3, 5, 8, 9};
    vector<vector<int>> result = su.substrAdd(num, 16);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        
        cout << endl;
    }
    return 0;
}

