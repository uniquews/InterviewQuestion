//
//  main.cpp
//  K_SumII
//
//  Created by Shuai Wang on 9/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//


// conversion of combinmation sum. i /ii
//knapsack problem

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    // combination sum without using one number in duplicate times
//    int kSum2 (vector<int> A, int target) {
//        vector<vector<int>> f (A.size() + 1, vector<int> (target + 1, 0));
//        
//        
//        int row = 0;
//        for (int j = 1; j <= target; j++) {
//            f[row][j] = INT_MIN;
//        }
//        
//        
//        for (int i = 1; i <= A.size(); i++) {
//            for (int j = 1; j <= target; j++) {
//                if (j - A[i - 1] >= 0) {
//                    // mention: The ith item and index i are different
//                    f[i][j] = max(f[i - 1][j - A[i - 1]] + 1, f[i - 1][j]);
//                } else {
//                    f[i][j] = f[i - 1][j];
//                }
//                
//            }
//        }
//        return f[A.size()][target];
//    }
    
    
    // space otptimization
//    int kSum2 (vector<int> A, int target) {
//        vector<int> f (target + 1);
//        for (int i = 1; i <= target; i++) {
//            f[i] = INT_MIN;
//        }
//        
//        f[0] = 0;
//        for (int i = 1; i <= A.size(); i++) {
//            for (int j = target; j >= 0; j --) {
//                if (j - A[i - 1] >= 0) {
//                    f[j] = max(f[j], f[j - A[i - 1]] + 1);
//                }
//                
//            }
//        }
//        
//        return f[target];
//
//    }


    // combination sum with one item duplicate use
    int kSum2 (vector<int> A, int target) {
        vector<int> f (target + 1);
        for (int i = 1; i <= target; i++) {
            f[i] = INT_MIN;
        }
        
        f[0] = 0;
        
        int result = 0;
        
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 0; j <= target; j++) {
                if (j - A[i - 1] >= 0) {
                    int tmp = f[j];
                    f[j] = max(f[j], f[j - A[i - 1]] + 1);
                    if (j == target && f[j] - tmp >= 0  && f[j] > 0) {
                        result++;
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
    vector<int> A = {2,3,6,4};
    cout << su.kSum2(A, 7) << endl;
    return 0;
}

