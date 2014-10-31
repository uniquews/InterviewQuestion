//
//  main.cpp
//  MergeSort
//
//  Created by Shuai Wang on 8/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector> 

using namespace std;



//class Solution {
//
//public:
//    static void mergeSort (vector<int> &arr) {
//    
//        vector<int> helper (arr.size());
//        
//        mergesort(arr, helper, 0, (int)arr.size() - 1);
//        return;
//    }
//    
//    
//    static void mergesort (vector<int> &arr, vector<int> &helper, int left, int right) {
//        if (left < right) {
//            int middle = (left + right) / 2;
//            mergesort(arr, helper, left, middle);
//            mergesort(arr, helper, middle + 1, right);
//            merge(arr, helper, left, middle, right);
//        }
//        
//        return;
//    }
//    
//    static void merge (vector<int> &arr, vector<int> &helper, int left, int middle, int right) {
//        for (int i = left; i <= right; i++) {
//            helper[i] = arr[i];
//        }
//        
//        int leftBegin = left;
//        int rightBegin = middle + 1;
//        int current = leftBegin;
//        
//        while (leftBegin <= middle && rightBegin <= right) {
//            if (helper[leftBegin] <= helper[rightBegin]) {
//                arr[current++] = helper[leftBegin++];
//            } else {
//                arr[current++] = helper[rightBegin++];
//            }
//        }
//        
//        
//        int remain = middle - leftBegin;
//            
//        for (int i = 0; i <= remain; i++) {
//            arr[current + i] = helper[leftBegin + i];
//        }
//        
//        
//        return;
//    
//    }
//    
//
//};

class Solution {
public:
    int * mergeSort(int A[], int n) {
        if (n < 2) {
            return A;
        }
        
        int mid = n / 2;
        int *arr1 = mergeSort(A, mid);
        int *arr2 = mergeSort(A + mid, n - mid);
        return merge(arr1, mid, arr2, n - mid);
        
    }
    
    int * merge(int A[], int size1, int B[], int size2) {
        int *result = new int[size1 + size2];
        int i = 0;
        int j = 0;
        while ((i < size1) && (j < size2)) {
            if (A[i] <= B[j]) {
                result[i + j] = A[i];
                i++;
            } else {
                result[i + j] = B[j];
                j++;
            }
            
        }
        
        while (i < size1) {
            result[i + j] = A[i];
            i++;
        }
        
        while (j < size2) {
            result[i + j] = B[j];
            j++;
        }
        
        return result;
        
    }
    
};

int main(int argc, const char * argv[])
{

    int a[] ={2,1,4,3,5,2,5,6,2};
    Solution su;
    int *result = su.mergeSort(a, 9);

    for (int i = 0; i < 9; i++) {
        cout << result[i];
    }
    return 0;
}

