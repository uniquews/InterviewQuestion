//
//  main.cpp
//  Find_Median
//
//  Created by Shuai Wang on 9/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
    int findMedian(int n, int A[]) {
        int pivot;
        int minimumGap = INT_MAX;
        int result;
        for (int i = 0; i < n; i++) {
            pivot = A[i];
            int index = partition(A[i], n, A[]);
            if (abs((index - 0) - (n - 1 - index)) < minimunGap) {
                minimunGap = (abs((index - 0) - (n - 1 - index));
                              result = A[index];
                              }
                              }
                              return result;
                              }
                              
                              int partition (int pivot, int n, int A[]) {
                                  int left = 0;
                                  int right = n - 1;
                                  
                                  while (left <= right) {
                                      while (A[left] < pivot) {
                                          left++;
                                      }
                                      
                                      while (A[right] > pivot) {
                                          right--
                                      }
                                      
                                      if (left <= right) {
                                          swap(A[left], A[right]);
                                          left++;
                                          right--;
                                      }
                                  }
                                  
                                  return left;
                              }
                              
                              
                              
                              

};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

