//
//  main.cpp
//  Subarray4
//
//  Created by Shuai Wang on 9/4/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> findSubarray(vector<int> A) {
        int prevSum = 0;
        unordered_map <int, int> _map;
        vector<vector<int>> result;
        _map[0] = -1;
        
        for (int i = 0; i < A.size(); i++) {
            vector<int> eachResult;
            prevSum = prevSum + A[i];
            
            if (_map.find(prevSum) == _map.end()) {
                _map[prevSum] = i;
            } else {
                eachResult.push_back(_map[prevSum] + 1);
                eachResult.push_back(i);
                result.push_back(eachResult);
            }
        
        }
        
        return result;
    
    }

};


int main(int args, const char * argv[])
{

    // insert code here...
    
    Solution su;
    vector<int> A = {-2,1,0,-3,4,-1,2, 1,-5,4};
    vector<vector<int>> result = su.findSubarray(A);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " " ;
        }
        cout << endl;
    }
    
    cout << endl;
   
    return 0;
}

