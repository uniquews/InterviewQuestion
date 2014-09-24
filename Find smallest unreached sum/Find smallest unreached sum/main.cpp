//
//  main.cpp
//  Find smallest unreached sum
//
//  Created by Shuai Wang on 9/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:
    int findSmallest(vector<int> A) {
        int result = 1;
        
        if (A.size() == 0) {
            return 1;
        }
        
        for (int i = 0; i < (int)A.size() && A[i] <= result; i++) {
            result = result + A[i];
        }
        
        return result;
    
    }

};

int main(int argc, const char * argv[])
{

    vector<int> A1 = {1, 3, 6, 10, 11, 15};
    Solution su1;
    cout << su1.findSmallest(A1) << endl;
    
    vector<int> A2 = {1, 1, 1, 1};
    Solution su2;
    cout << su2.findSmallest(A2) << endl;
    
    vector<int> A3 = {1, 1, 3, 4};
    Solution su3;
    cout << su3.findSmallest(A3) << endl;
    
    vector<int> A4 = {1, 2, 5, 10, 20, 40};
    Solution su4;
    cout << su4.findSmallest(A4) << endl;
    
    vector<int> A5 = {1, 2, 3, 4, 5, 6};
    Solution su5;
    cout << su5.findSmallest(A5) << endl;
    
    
    return 0;
}

