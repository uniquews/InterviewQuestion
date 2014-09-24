//
//  main.cpp
//  Minimun sort subarray
//
//  Created by Shuai Wang on 9/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    vector<int> minimunsortSubarray(vector<int> &A) {
        if (A.size() == 0) {
            return vector<int> {};
        }
        
        int maxNum = A[0];
        int minNum = A[A.size() - 1];
        
        vector<int> result = {INT_MAX, INT_MIN};
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] >= maxNum) {
                maxNum = A[i];
                continue;
            } else {
                if (result[1] < i) {
                    result[1] = i;
                }
            }
        
        }
        
        for (int i = (int)A.size() - 1; i >= 0; i--) {
            if (A[i] <= minNum) {
                minNum = A[i];
                continue;
            } else {
                if (result[0] > i) {
                    result[0] = i;
                }
            }
        }
        

        if (result[0] == INT_MAX || result[1] == INT_MIN) {
            return vector<int> {-1, -1};
        }
       
        return result;
    
    }

};

int main(int argc, const char * argv[])
{

    Solution su;
    vector<int> A1 = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
//    vector<int> A2 = {2, 1};
    vector<int> result = su.minimunsortSubarray(A1);
//    vector<int> result2 = su.minimunsortSubarray(A2);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

