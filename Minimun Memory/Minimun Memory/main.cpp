//
//  main.cpp
//  Minimun Memory
//
//  Created by Shuai Wang on 9/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumMemory(vector<int> nums) {
        if (nums.size() == 0) {
            return -1;
        }
        
        int minimumLen = INT_MAX;
        int result = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            while (i < nums.size() && nums[i] == 1) {
                i++;
            }
            
            int end = i;
            while (end < nums.size() && nums[end] == 0) {
                end++;
            }
            
            if (end - i >= 2 && end - i < minimumLen) {
                minimumLen = end - i;
                result = i;
                i = end;
            }
            
        }
        return result;
    }
    
};

int main(int argc, const char * argv[])
{

//    vector<int> nums = {1,1,1,0,0,0,0,1,0,0,1,1};
//    vector<int> nums = {1,1,1,1,1};
    vector<int> nums = {0,0,0,0,0,0};
    Solution su;
    cout << su.minimumMemory(nums) << endl;
    
    return 0;
}

