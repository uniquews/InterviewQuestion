//
//  main.cpp
//  Heap Sort
//
//  Created by Shuai Wang on 10/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace  std;

class Solution {

public:
    void buildHeap(vector<int> &nums) {
        if (nums.size() <= 1) {
            return;
        }
        
        int n = (int)nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) { // i = n / 2 - 1 保证了整个数组有偶数个数字时，叶子节点是n/2个nodes；而有奇数个数字时，叶子节点是n/2 + 1个nodes，因为叶子节点必须大于等于非叶子节点 (相当于是取了非叶子节点的最后一个)
            heapify(nums, i, n);
        }
    }
    
    void heapify(vector<int> &num, int root, int size) {
        
        while (root * 2 + 1 < size) {
            int left = root * 2 + 1;
            int right = root * 2 + 2;
            int checkpoint = root;
            
            if (left < size && num[left] > num[checkpoint]) {
                checkpoint = left;
            }
            
            if (right < size && num[right] > num[checkpoint]) {
                checkpoint = right;
            }
            
            if (checkpoint != root) {
                swap(num[checkpoint], num[root]);
                root = checkpoint; //交换到右边的是孩子，向右继续查看是否孩子和孙子之间满足Heap property
            } else {
                break; // 此节点已经满足heap property，由于是bottom-up建堆，所以不需要再继续向右查看孩子是否和孙子之间满足heap property
            }
        
        }
    
    }
    
    void heapsort(vector<int> &nums) {
        int n = (int)nums.size();
        while (n > 1) { // n
            swap(nums[0], nums[n - 1]);
            heapify(nums, 0, --n);  // logn
            
        }
        
    }

};

int main(int argc, const char * argv[])
{

    vector<int> A = {8, 5, 6, 3, 1,2,100,42,53,56,7};
    Solution su;
    su.buildHeap(A);
    su.heapsort(A);
    
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] <<endl;
    }
    
    return 0;
}

