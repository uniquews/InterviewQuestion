//
//  main.cpp
//  QuickSort
//
//  Created by Shuai Wang on 8/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void quickSort(vector<int> &A, int start, int end){
        if (A.size() == 0) {
            return;
        }
        if (start < end) {
            int index = partition(A, start, end);
            quickSort(A, start, index - 1);
            quickSort(A, index + 1, end);
        }
    
    }

    int partition(vector<int> &A, int start, int end) {
        int pivot = A[end];
        int leftTail = start - 1;
        for (int rightHead = start; rightHead <= end - 1; rightHead++) {
            if (A[rightHead] <= pivot) {
                leftTail++;
                swap(A[leftTail], A[rightHead]);
            }
        }
        
        swap(A[leftTail + 1], A[end]);
        return leftTail + 1;
    }
    
};


int main(int argc, const char * argv[])
{

//    vector<int> a = {1,1,1,3,2,4,5,6,7,4,3,2};
//    vector<int> a = {8,9,1,5,13,7,100,30,2};
    vector<int> a = {8,9,7,5,2,10};
    int end = (int)a.size();
    
    Solution su;

    su.quickSort(a, 0, end-1);
    
    for(int i=0;i<end;i++){
        cout << a[i]<<" ";
    }
    return 0;
}

