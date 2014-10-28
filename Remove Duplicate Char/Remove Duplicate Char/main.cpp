//
//  main.cpp
//  Remove Duplicate Char
//
//  Created by Shuai Wang on 10/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    // sort with constant space and in-place
//    void removeDuplicate(vector<char> &A) {
//        if (A.size() == 0) {
//            return;
//        }
//        
//        sort(A.begin(), A.end());
//        
//        int cur = 0;
//        for (int i = 1; i < A.size(); i++) {
//            if (A[i] == A[cur]) {
//                continue;
//            } else {
//                A[++cur] = A[i];
//            }
//            
//        }
//        
//        A.resize(cur + 1);
//        return;
//        
//    }
//    
//    
//};

//class Solution {
//public:
//    // sort with constant space and in-place
//    void removeDuplicate(vector<char> &A) {
//        if (A.size() == 0) {
//            return;
//        }
//        
//        vector<bool> hashMap(256, false);
//        int cur = 0;
//        hashMap[A[0]] = true;
//        for (int i = 1; i < A.size(); i++) {
//            if (hashMap[A[i]] == true) {
//                continue;
//            } else {
//                A[++cur] = A[i];
//                hashMap[A[i]] = true;
//            }
//        }
//        
//        A.resize(cur);
//        return;
//    }
//    
//    
//};

class Solution {
public:
    // sort with constant space and in-place
    void removeDuplicate(vector<char> &A) {
        if (A.size() == 0) {
            return;
        }
        int cur = 0;
        for (int i = 1; i < A.size(); i++) {
            bool dup = false;
            for (int j = 0; j < i; j++) {
                if (A[j] == A[i]) {
                    dup = true;
                    break;
                }
            }
            
            if (dup) {
                continue;
            } else {
                A[++cur] = A[i];
            }
            
        }
        
        return A.resize(cur + 1);
    }
    
    
};

int main(int argc, const char * argv[])
{

    vector<char> A = {'a', 'a', 'a', 'b'};
//    vector<char> A = {'w','a','b','x','y','h', 'w', 'b','m','n','m'};
    Solution su;
    su.removeDuplicate(A);
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << endl;
    }
    return 0;
}

