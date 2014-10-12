//
//  main.cpp
//  Single Number Sorted
//
//  Created by Shuai Wang on 10/12/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &A) {
        if (A.size() == 0) {
            return -1;
        }
        int start = 0;
        int end = (int)A.size() - 1;
       
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] != A[mid - 1] && A[mid] != A[mid + 1]) {
                return A[mid];
            }
            
            if (mid % 2 == 0) {
                if (A[mid] == A[mid + 1]) { // 没有妨碍到前面，前面是正确
                    start = mid;
                } else if (A[mid] == A[mid - 1]){// 没有妨碍到后面，后面面是正确
                    end = mid;
                    
                }
            
            } else {
                if (A[mid] == A[mid + 1]) {
                    end = mid;
                } else if (A[mid] ==  A[mid - 1]) {
                    start = mid;
                }
           
            }
          
        }
        if (start == 0) {
            return A[0];
        }
        
        if (end == (int)A.size() - 1) {
            return A[A.size() - 1];
        }
        
        return -1;
        
    }
    
    
};

int main(int argc, const char * argv[])
{

    Solution su;
    vector<int> A = {1,2,2,3,3,5,5,6,6,8,8,9,9,10,10,11,11};
    cout << su.singleNumber(A) << endl;
    return 0;
}

