//
//  main.cpp
//  Hoare
//
//  Created by Shuai Wang on 11/13/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int partition(vector<int> &A, int start, int end) {
        int pivot = A[start];
        int leftTail = start;
        int rightHead = end;
        while (true) {
            while (rightHead >= 0 && A[rightHead] > pivot) {
                rightHead--;
            }
            
            while (leftTail <= end && A[leftTail] < pivot) {
                leftTail++;
            }
            
            if (leftTail < rightHead) {
                swap(A[leftTail], A[rightHead]);
                rightHead--;
                leftTail++;
            } else {
                return leftTail - 1;
            }
        
        }
    
    }
    
    void quicksort(vector<int> &A, int start, int end) {
        int index = partition(A, start, end);
        if (start < index) {
            quicksort(A, start, index);
        }
        
        
        if (index + 1 < end) {
            quicksort(A, index + 1, end);
        }
        return;
    }

};

int main(int argc, const char * argv[]) {
    vector<int> a = {8,9,7,5,2,10};
    int end = (int)a.size();
    
    Solution su;
    
    su.quicksort(a, 0, end-1);
    
    for(int i=0;i<end;i++){
        cout << a[i]<<" ";
    }

    return 0;
}
