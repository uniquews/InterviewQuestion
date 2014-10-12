//
//  main.cpp
//  kthNumberInMatrix
//
//  Created by Shuai Wang on 10/12/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace  std;

class Solution {
public:
    int kthNumberInMatrix(vector<vector<int>> &matrix, int k) {
        if (matrix.size() == 0) {
            return -1;
        }
        
        
        
        priority_queue<int, vector<int>> q;
        
        int row = (int)matrix.size();
        int column = (int)matrix[0].size();
        
        for (int i = 0; i < column; i++) {
            for (int j = 0; j < row; j++) {
                if (q.size() < k) {
                    q.push(matrix[j][i]);
                } else {
                    if (matrix[j][i] < q.top()) {
                        q.push(matrix[j][i]);
                        q.pop();
                    }
                }
            }
            
        }
        
        return q.top();
        
    }
};

int main(int argc, const char * argv[])
{

    vector<vector<int>> matrix = {{1000, 2000, 3000, 4000}, {1,2,3,4}, {8,9,10,11}, {5, 13, 59, 78}};
    
    Solution su;
    cout << su.kthNumberInMatrix(matrix, 7) <<endl;
    return 0;
}

