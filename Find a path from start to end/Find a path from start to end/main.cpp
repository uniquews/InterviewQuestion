//
//  main.cpp
//  Find a path from start to end
//
//  Created by Shuai Wang on 10/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>> &matrix, int startX, int startY, int endX, int endY) {
        if (matrix.size() == 0) {
            return false;
        }
        
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        
        return dfs(startX, startY, endX , endY, matrix, visited);
        
    }
    
    bool dfs(int x, int y, int m, int n, vector<vector<char>> &matrix, vector<vector<bool>> &visited) {
        if (x == m && y == n) {
            return true;
        }
        
        if (x < 0 || y < 0 || x == matrix.size() || y == matrix[0].size()) {
            return false;
        } else if (visited[x][y]) {
            return false;
        } else if (matrix[x][y] == 'X') {
            return false;
        } else {
            visited[x][y] = true;
            if (dfs(x + 1, y, m, n, matrix, visited) || dfs (x, y + 1, m, n, matrix, visited) || dfs(x - 1, y, m, n, matrix, visited) || dfs(x, y - 1, m, n, matrix, visited)) {
                return true;
            }
        }
        
        visited[x][y] = false;
        
        return false;
        
    }
    
};


int main(int argc, const char * argv[])
{

    vector<vector<char>> matrix = {{'O', 'X', 'O','X'}, {'O', 'X', 'O', 'X'}, {'X', 'O', 'O', 'O'}, {'O', 'O', 'O', 'O'}};
    
    Solution su;
    cout << su.isValid(matrix, 0, 0, 3, 3) << endl;
    return 0;
}

