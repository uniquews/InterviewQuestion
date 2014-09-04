//
//  main.cpp
//  Pow_of_pair
//
//  Created by Shuai Wang on 9/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findNumberOfPairs(vector<int> X, vector<int> Y) {
        
        int result = 0;
        int m = (int)X.size();
        int n = (int)Y.size();
        vector<double> X1;
        vector<double> Y1;
        for (int i = 0; i < m; i++) {
            X1.push_back(double(log(X[i])) / X[i]);
//            cout << X1[i] << " ";
        }
        
//        cout << endl;
        
        for (int j = 0; j < n; j++) {
            Y1.push_back(double(log(Y[j])) / Y[j]);
//            cout << Y1[j] << " ";
        }
        
//        cout << endl;
        
        sort(X1.begin(), X1.end());
        sort(Y1.begin(), Y1.end());
        
        for (int i = 0; i < m; i++) {
            int index = binary_search(X1[i], Y1, n);
            cout << X1[1] <<" ";
            if (Y1[index] == X1[i]) {
                result += index;
            } else {
                result += index;
            }
            
        }
        
        
        return result;
    }
    
    
    int binary_search(double target, vector<double> Y1, int n) {
        int start = 0;
        int end = n - 1;
        int mid;
        
        while (start + 1 < end) {
            
            mid = start + (end - start) / 2;
            if (Y1[mid] == target) {
                start = mid;
            } else if (Y1[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        
        if (Y1[start] == target) {
            return start;
        }
        
        if (Y1[end] == target) {
              return end;
        }
        
        
        if (Y1[start] > target) {
            return start;
        }
        
        if (Y1[end] < target) {
            return end + 1;
        }
        
        if (Y1[start] < target && target < Y1[end]) {
            return end;
        }
        
        return -1;
    }
              
};

int main(int argc, const char * argv[])
{

//    int X[] = {2,1,6};
//    int Y[] = {1,5};
    
//    
//    int X[] = {10, 19, 18};
//    int Y[] = {11, 15, 9};
    
    vector<int> X = {1000, 2000, 3000};
    vector<int> Y = {1000, 2000, 3000};
    
    Solution su;
    cout << su.findNumberOfPairs(X, Y) << endl;
    
    return 0;
}

