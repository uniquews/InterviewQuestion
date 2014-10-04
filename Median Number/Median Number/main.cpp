//
//  main.cpp
//  Median Number
//
//  Created by Shuai Wang on 10/4/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class Solution {

public:
    double medianNum(vector<int> &num) {
        if (num.size() == 0) {
            return 0;
        }
        
        if (num.size() == 1) {
            return num[0];
        }
        
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < num.size(); i++) {
            if (maxHeap.size() == 0) {
                maxHeap.push(num[i]);
            } else if (maxHeap.size() != 0 && maxHeap.top() >= num[i]) {
                maxHeap.push(num[i]);
            } else if (minHeap.size() != 0 && minHeap.top() <= num[i]) {
                minHeap.push(num[i]);
            } else {
                maxHeap.push(num[i]);
            }
            
            if ((int)maxHeap.size() - (int)minHeap.size() > 1) {
                int tmp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(tmp);
            }
            
            if ((int)minHeap.size() - (int)maxHeap.size() > 1) {
                int tmp = minHeap.top();
                minHeap.pop();
                maxHeap.push(tmp);
            }
            
        }
        
        if (((int)minHeap.size() + (int)maxHeap.size()) % 2 == 0) {
            double median = (minHeap.top() + maxHeap.top()) / 2.00;
            return median;
        } else {
            if (minHeap.size() > maxHeap.size()) {
                return minHeap.top();
            } else {
                return maxHeap.top();
            }
        }
      
    
    }


};Í

int main(int argc, const char * argv[])
{

    vector<int> num = {7,3,5,6,8,10};
    Solution su;
    
    cout << su.medianNum(num) << endl;
    return 0;
}

