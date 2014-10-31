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
        
        
        int index = partition(A, start, end);
        if (start < index - 1) {
            quickSort(A, start, index - 1);
        }
        
        if (index < end) {
            quickSort(A, index, end);
        }
        
        return;
    }
    
    int partition(vector<int> &A, int left, int right) {
        int mid = left + (right - left) / 2;
        int pivot  = A[mid];
        while (left <= right) {
            while (A[left] < pivot) {
                left++;
            }
            
            while (A[right] > pivot) {
                right--;
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

//class Solution {
//
//public:
//    
//    void quickSort(vector<int> &arr, int left, int right) {
//        int partitionIndex = partition(arr, left, right);
//        
//        if (left < partitionIndex ) {
//            quickSort(arr, left, partitionIndex);
//            
//        }
//        
//        if (partitionIndex + 1 < right) {
//            quickSort(arr, partitionIndex + 1, right);
//        }
//    
//    }
//    
//    int partition(vector<int> &arr, int left, int right) {
//        int pivot = arr[left + (right - left) / 2];
//        while (left <= right) {
//            while (arr[left] < pivot) {
//                left++;
//            }
//            
//            while (arr[right] > pivot) {
//                right--;
//            }
//            
//            if (left <= right) {
//                swap(arr, left, right);
//                left++;
//                right--;
//            }
//        
//        }
//       
//        return right;
//    }
//    
//    void swap(vector<int> &arr, int left, int right) {
//        int temp = arr[right];
//        arr[right] = arr[left];
//        arr[left] = temp;
//        return;
//    }
//    
//
//};

int main(int argc, const char * argv[])
{

//    vector<int> a = {1,1,1,3,2,4,5,6,7,4,3,2};
    vector<int> a = {1,1,2,1,1,1,5,5};
    int end = (int)a.size();
    
    Solution su;
    
    
    su.quickSort(a, 0, end-1);
    
    for(int i=0;i<end;i++){
        cout << a[i]<<" ";
    }
    return 0;
}

