//
//  main.cpp
//  Find_Number_Zero
//
//  Created by Shuai Wang on 9/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
	int solver (vector<int> A) {
        
		int left = 0;
		int right = A.size() - 1;
		int mid;
		while (left + 1 < right) {
			mid = left + (right - left) / 2;
			if (A[mid] == 0) {
				right = mid;
            } else if (A[mid] == 1) {
                left = mid;
            }
        }
        
        
        if (A[left] == 0) {
            return (int)A.size() - left;
        }
        
        if (A[left] == 1) {
            if (A[right] == 0) {
                return (int) A.size() - right;
            } else {
                return 0;
            }
        }
        
        if (A[right] == 1) {
            return 0;
        }
        return -1;
    }
    
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

