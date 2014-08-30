//
//  main.cpp
//  Matrix_Sum
//
//  Created by Shuai Wang on 8/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    
    vector<vector<int>> computeSums(vector<vector<int>> &input) {
        if (input.size() == 0 || input[0].size() == 0) {
            return vector<vector<int>> ();
        }
        
        
        //initialize the first row
        for (int col = 1; col < input[0].size(); col++) {
            input[0][col] = input[0][col - 1] + input[0][col];
        }
        
        //initialize the first column
        for (int row = 1; row < input.size(); row++) {
            input[row][0] = input[row - 1][0] + input[row][0];
        }
        
    
        for (int i = 1; i < input.size(); i++) {
            for (int j = 1; j < input[i].size(); j++) {
                input[i][j] = input[i - 1][j] + input[i][j - 1] + input[i][j] - input[i - 1][j - 1];
            }
        }
        
        return input;
    }
    
    void display (vector<vector<int>> output) {
        vector<vector<int>> :: iterator it = output.begin();
        for (; it != output.end(); it ++) {
            vector<int> :: iterator it2 = it->begin();
            for (; it2 != it->end(); it2++) {
                cout << *it2 << " ";
            }
            
            cout << endl;
        }
    
    }


};

int main(int argc, const char * argv[])
{

    Solution su;
    vector<vector<int>> matrix1 = {{1},{1},{1},{1}};
    vector<vector<int>> matrix2 = {{1,1,1,1}};
    vector<vector<int>> matrix3 = {{1,1,8}, {6,3,0}, {2,4,10}};

    su.display(su.computeSums(matrix1));
    su.display(su.computeSums(matrix2));
    su.display(su.computeSums(matrix3));
    
    
    return 0;
}

