//
//  main.cpp
//  Tree Height Given Parent Array
//
//  Created by Shuai Wang on 10/5/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int height(vector<int> &A) {
        if (A.size() == 0) {
            return 0;
        }
        
        
        int result = 0;
        int len = 1;
        for (int i = 0; i < A.size(); i++) {
            dfs(i, A, result, len);
        }
        
    
        return result;
    }
    
    
    void dfs(int start, vector<int> &A, int &result, int len) {
        if (A[start] == -1) {
            result = max(result, len);
            return;
        }
        
        int nextPos = A[start];
        dfs(nextPos, A, result, len + 1);
        
        return;
    
    }

};

int main(int argc, const char * argv[])
{

//    vector<int> A = {1, 5, 5, 2, 2, -1, 3};
    vector<int> A = {-1, 0, 0, 1, 1, 3, 5};
    Solution su;
    cout << su.height(A) <<endl;
    return 0;
}

