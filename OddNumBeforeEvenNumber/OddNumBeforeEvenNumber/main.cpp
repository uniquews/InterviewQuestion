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

//class Solution {
//    
//public:
//    
//    vector<int> reArrange(vector<int> &A) {
//        int start = 0;
//        int end = A.size() - 1;
//        
//        
//        
//        while (start <= end) {
//            while (A[start] % 2 != 0) {
//                start++;
//            }
//            
//            while (A[end] % 2 == 0) {
//                end--;
//            }
//            
//            if (start <= end) {
//                int tmp = A[start];
//                A[start] = A[end];
//                A[end] = tmp;
//            }
//            
//            start++;
//            end--;
//            
//        }
//        
//        return A;
//    }
//    
//};

class Solution {

public:
    
    vector<int> reArrange(vector<int> &A) {
        if (A.size() == 0) {
            return A;
        }
        
        if (A.size() == 1) {
            return A;
        }
        
        
        int slow = 0;
        int fast = 1;
        
        while (slow <= A.size() - 1 && fast <= A.size() - 1) {
        
            while (slow <= A.size() - 1 && (A[slow] & 1) == 1) {
                slow++;
            }
            
            while (fast <= A.size() - 1 && (A[fast] & 1) == 0) {
                fast++;
            }
            
            if (slow <= A.size() - 1 && fast <= A.size() - 1) {
                swap(A[slow], A[fast]);
                slow++;
                fast++;
            }
            
        
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

