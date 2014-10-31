//
//  main.cpp
//  Tetris
//
//  Created by Shuai Wang on 10/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    void Teris(vector<vector<int>> &matrix) {
        if (matrix.size() == 0) {
            return;
        }
        
        int cur = 0;
        for (int i = 0; i < matrix.size(); i++) {
            vector<int> tmp = matrix[i];
            if (isMark(tmp)) {
                continue;
            } else {
                matrix[cur++] = matrix[i];
            }
        }
        
        for (int i = cur; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] = 0;
            }
        }
    
    }
    
    bool isMark(vector<int> eachRow) {
        for (int i = 0; i < eachRow.size(); i++) {
            if (eachRow[i] == 0) {
                return false;
            }
        }
        return true;
    }

};

int main(int argc, const char * argv[])
{

//   vector<vector<int>> matrix = {{1,1,1,1}, {0,0,0,0}, {1,1,1,1}, {0,0,1,0}, {1,1,1,1}};
    
    
    
//    vector<vector<int>> matrix = {{1,0,1,1}, {0,0,1,0}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
    
//    vector<vector<int>> matrix = {{1,1,1,1}, {1,1,1,1}, {0,0,0,0,}, {0,0,1,0}, {1,1,0,1}};
    
    
    
//        vector<vector<int>> matrix = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
    
    
    
    vector<vector<int>> matrix = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
    
    Solution su;
    su.Teris(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

