//
//  main.cpp
//  Kth Permutation
//
//  Created by Shuai Wang on 10/5/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    vector<int> kthPermutation(vector<int> &input, int k) {
        if (input.size() == 0) {
            return vector<int> {};
        }
        
        sort(input.begin(), input.end());
        vector<int> result;
        int n = (int)input.size();
        
        while (n > 0) { //代表有几个数，所以n一定要递减到1，这道result才会把input中所有的数都放进去
            int fac = getFactorial(n - 1);
            int start = (k - 1) / fac + 1;
            result.push_back(input[start - 1]);
            n--;
            k = k - (start - 1) * fac; // k 永远不可能为0
        }
        
        return result;
        
    
    }
    
    int getFactorial(int n) {
        if (n == 0) {
            return 1;
        }
        int result = 1;
        while (n > 0) {
            result = result * n;
            n--;
        }
        
        return result;
    }


};

int main(int argc, const char * argv[])
{

    vector<int> input = {1,2,3};
    Solution su;
    int k = 6;
    vector<int> result = su.kthPermutation(input, k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] <<endl;
    }
    return 0;
}

