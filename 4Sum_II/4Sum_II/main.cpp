//
//  main.cpp
//  4Sum_II
//
//  Created by Shuai Wang on 9/4/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>


//n个数里区K个数完成target的方案

using namespace std;
//
//class Solution {
//public:
//    
//    int fourSum2(vector<int> num, int k, int target) {
//        int n = (int)num.size();
//        if (n < k || n == 0) {
//            return 0;
//        }
//        
//        int _min = 0
//        int _max = 0;
//        
//        
//        vector<vector<vector<int>>> f(n, vector<vector<int>> (k, vector<int> (target + 1)));
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < k; j++) {
//                if (i < j) {
//                    for (int m = 0; i < target + 1; m++) {
//                    
//                    }
//                }
//            }
//        }
//    }
//    
//
//};

class Solution {
public:
    
    
    vector<vector<vector<int>>> kSum2(vector<int> num, int k , int target) {
        vector<vector<vector<int>>> finalResult;
        for (int targetK = 1; targetK < num.size(); targetK++) {
            vector<vector<int>> inSameK = fourSum2(num, targetK, target);
            if (inSameK.size() != 0) {
                finalResult.push_back(inSameK);
            }
        }
        return finalResult;
    }
    
    
    vector<vector<int>> fourSum2(vector<int> num, int k, int target) {
        if (num.size() == 0 || num.size() < k) {
            return vector<vector<int>>{};
        }
        
        int result = 0;
        vector<vector<int>> totalResult;
        vector<int> eachResult;
        dfs(num, k, target, 0, result, 0, totalResult, eachResult);
        
        return totalResult;
    }
    
    void dfs (vector<int> &num, int k, int target, int cur, int &result, int left, vector<vector<int>> &totalResult, vector<int> &eachResult) {
        if (cur == k && target == 0) {
            result++;
            totalResult.push_back(eachResult);
            return;
        }
        
        
        for (int i = left; i < num.size(); i++) {
            eachResult.push_back(num[i]);
            dfs(num, k, target - num[i], cur + 1, result, i + 1, totalResult, eachResult);
            eachResult.pop_back();
        }
        
        return;
        
    }

};

int main(int argc, const char * argv[])
{

    Solution su;
    vector<int> num = {-1, 0, 4, 5, -2, 3, 7, 8, 1};
    vector<vector<vector<int>>> finalResult;
    finalResult = su.kSum2(num, 6, 9);
    cout << "array is: " << endl;
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    cout << "target: " << 9 << endl;
    cout << "k: " << 4 << endl;
    for (int n = 0; n < finalResult.size(); n++) {
        vector<vector<int>> result = finalResult[n];
        for (int i = 0 ; i < result.size(); i++) {
            vector<int> eachResult = result[i];
            for (int j =0; j < eachResult.size(); j++) {
                cout << eachResult[j] << " ";
            }
            cout << endl;
        }
    
    }
    

    
    return 0;
}

