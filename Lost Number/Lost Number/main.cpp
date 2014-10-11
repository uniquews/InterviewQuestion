//
//  main.cpp
//  Lost Number
//
//  Created by Shuai Wang on 10/10/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace  std;

class Solution {
    
public:
    string lostNumber(vector<int> &A) {
        string result = "";
        int start = 0; // the first check number
        int i = 0;
        
        while (i < A.size() - 1) {
            if (A[i] == start) {
                start = A[i] + 1;
                i++;
                continue;
            } else {
                int count = A[i] - start;
                if (count > 1) {
                    result.append(to_string(start)).append("-").append(to_string(A[i] - 1)).append(",");
                } else if (count == 1) {
                    result.append(to_string(start)).append(",");
                }
                start = A[i] + 1;
                i++;
            }
            
        }
        
        if (A.back() == 99) {
            int count = A.back() - start;
            if (count > 1) {
                result.append(to_string(start)).append("-").append(to_string(98));
            } else if (count == 1) {
                result.append(to_string(start));
            }
        } else {
            int count = A.back() - start;
            if (count > 1) {
                result.append(to_string(start)).append("-").append(to_string(A.back() - 1)).append(",");
            } else if (count == 1) {
                result.append(to_string(start)).append(",");
            }
            count = 99 - A.back();
            if (count == 1) {
                result.append(to_string(99));
            } else if (count > 1){
                result.append(to_string(A.back() + 1).append("-").append(to_string(99)));
            }
            
        }
        
        start = 100;
        return result;
    }
    
    
    
};






int main(int argc, const char * argv[])
{
    
    //    vector<int> A = {0,1,2,50,52,75};
    //    vector<int> A = {0};
//    vector<int> A = {1,4,99};
//    vector<int> A = {1,4};
    vector<int> A;
    for (int i = 0; i < 100; i++) {
        A.push_back(i);
    }
    Solution su;
    cout << su.lostNumber(A) <<endl;
    return 0;
}

