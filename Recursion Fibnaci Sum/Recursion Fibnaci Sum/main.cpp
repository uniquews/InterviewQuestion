//
//  main.cpp
//  Recursion Fibnaci Sum
//
//  Created by Shuai Wang on 11/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;
class Solution {
public:
    
    int recursion (int n) {
        int sum = 0;
        dfs(n, sum);
        return sum;
    }
    
    int dfs(int n, int &sum) {
        if (n == 1) {
            return 0;
        }
        
        if (n == 2) {
            
            return 1;
        }
        
        int tmp = sum;
        int num = dfs(n - 1, tmp) + dfs(n - 2, tmp);
        tmp +=num;
        sum = tmp;
        return num;
    }
    
};

int main(int argc, const char * argv[]) {
    int n = 6;
    Solution su;
    cout << su.recursion(n) << endl;
    return 0;
}
