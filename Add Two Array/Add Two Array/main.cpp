//
//  main.cpp
//  Add Two Array
//
//  Created by Shuai Wang on 11/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addArray(vector<int> &A, vector<int> &B) {
        if (A.size() == 0 && B.size() == 0) {
            return vector<int> {};
        }
        
        if (A.size() == 0) {
            return B;
        }
        
        if (B.size() == 0) {
            return A;
        }
        
        int a = (int)A.size() - 1;
        int b = (int)B.size() - 1;
        
        vector<int> result;
        vector<int> :: iterator it = result.begin();
        int carry = 0;
        
        while (a >= 0 && b >= 0) {
            int tmp = A[a] + B[b] + carry;
            int digit = tmp % 10;
            result.insert(it, digit);
            carry = tmp / 10;
            a--;
            b--;
            it = result.begin();
            
        }
        
        while (a >= 0) {
            int tmp = A[a] + carry;
            int digit = tmp % 10;
            result.insert(it, digit);
            carry = tmp / 10;
            it = result.begin();
            a--;
        }
        
        while (b >= 0) {
            int tmp = B[b] + carry;
            int digit = tmp % 10;
            result.insert(it, digit);
            carry = tmp / 10;
            it = result.begin();
            b--;
        }
        
        if (carry != 0) {
            result.insert(it, carry);
        }
        
        return result;
        
    }
    
    
};

int main(int argc, const char * argv[]) {
    vector<int> A = {4,2,3,4};
    vector<int> B = {9,4,7,7,8};
    Solution su;
    vector<int> result = su.addArray(A, B);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    cout << endl;
    return 0;
}
