//
//  main.cpp
//  Find K Largest Sum In Two Sorted Array
//
//  Created by Shuai Wang on 10/15/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// k largest sum in two sorted arrays

class Solution {
public:
    vector<int> FindKLargestSum (vector<int> &A, vector<int> &B, int k) {
        if (A.size() == 0 && B.size() == 0) {
            return vector<int> {};
        }
        
        vector<int> sum;
        int i = (int)A.size() - 1;
        int j = (int)B.size() - 1;
        while (k > 0) {
            sum.push_back(A[i] + B[j]);
            int tmp1 = INT_MIN;
            int tmp2 = INT_MIN;
            if (i - 1 >= 0) {
                tmp1 = A[i - 1] + B[j];
            }
            
            if (j - 1 >= 0) {
                tmp2 = A[i] + B[j - 1];
            }
            
            if (tmp1 >= tmp2) {
                i--;
            } else {
                j--;
            }
            
            k--;
            
        }
        
        return sum;
    }
    
};

int main(int argc, const char * argv[])
{

    vector<int> A = {1,2,1000,2000};
    vector<int> B = {5,6,8,9};
    
    Solution su;
    vector<int> sum = su.FindKLargestSum(A, B, 5);
    
    for (int i = 0; i < sum.size(); i++) {
        cout << sum[i] << endl;
    
    }
    return 0;
}

