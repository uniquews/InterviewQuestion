//
//  main.cpp
//  OddNumBeforeEvenNumber
//
//  Created by Shuai Wang on 9/12/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    
    vector<int> reArrange(vector<int> &A) {
        int start = 0;
        int end = A.size() - 1;
        
        
        
        while (start <= end) {
            while (A[start] % 2 != 0) {
                start++;
            }
            
            while (A[end] % 2 == 0) {
                end--;
            }
            
            if (start <= end) {
                int tmp = A[start];
                A[start] = A[end];
                A[end] = tmp;
            }
            
            start++;
            end--;
            
        }
        
        return A;
    }
    
};

int main(int argc, const char * argv[])
{

    vector<int> A = {42,5,6,2,1,4,5,6,7};
    Solution su;
    su.reArrange(A);
    
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    
    cout << endl;
    return 0;
}

