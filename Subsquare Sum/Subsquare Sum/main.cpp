//
//  main.cpp
//  Subsquare Sum
//
//  Created by Shuai Wang on 9/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsquare(vector<vector<int>> &matrix, int k) {
        if (matrix.size() == 0) {
            return vector<vector<int>> {};
        }
        
        int row = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> result;
        
        for (int i = 0; i < row; i++) {
            vector<int> eachSum;
            for (int j = 0; j < column; j++) {
                
                if (i + k - 1 < row && j + k - 1 < column) {
                    int sum = getSum(matrix, i, j, k);
                    eachSum.push_back(sum);
                }
                
            }
            
            result.push_back(eachSum);
        }
        
        return result;
        
    }
    
    int getSum(vector<vector<int>> &matrix, int r, int c, int k) {
        int sum = 0;
        for (int i = r; i < r + k; i++) {
            for (int j = c; j < c + k; j++) {
                sum += matrix[i][j];
            }
        }
        
        return sum;
    }
    
};

int main(int argc, const char * argv[])
{

    vector<vector<int>> matrix = { {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    
    int k = 2;
    
    Solution su;
    vector<vector<int>> result = su.subsquare(matrix, k);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

