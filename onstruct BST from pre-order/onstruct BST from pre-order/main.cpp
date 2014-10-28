//
//  main.cpp
//  onstruct BST from pre-order
//
//  Created by Shuai Wang on 10/19/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    TreeNode *construct(vector<int> &A) {
        if (A.size() == 0) {
            return nullptr;
        }
        
        return divide(A, 0, (int)A.size() - 1);
    }
    
    TreeNode *divide(vector<int> &A, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        
        if (start == end) {
            TreeNode *node = new TreeNode(A[start]);
            return node;
        }
        
        TreeNode *root = new TreeNode (A[start]);
        int large = -1;
        for (int i = start; i <= end; i++) {
            if (A[start] < A[i]) {
                large = i;
            }
        }
        
        if (large == -1) {
            TreeNode *leftNode = divide(A, start + 1, end - 1);
            root->left = leftNode;
            return root;
        } else {
            TreeNode *leftNode = divide(A, start + 1, large - 1);
            TreeNode *rightNode = divide(A, large, end);
            root->left = leftNode;
            root->right = rightNode;
            return root;
        }
        
    }
    
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> stk;
        vector<int> result;
        if (root == nullptr) {
            return vector<int> {};
        }
        
        stk.push(root);
        while (stk.size() != 0) {
            TreeNode *tmp = stk.top();
            result.push_back(tmp->val);
            stk.pop();
            
            if (tmp->right != nullptr) {
                stk.push(tmp->right);
            }
            
            if (tmp->left != nullptr) {
                stk.push(tmp->left);
            }
        }
        
        return result;
    }
    
};

int main(int argc, const char * argv[])
{

    vector<int> A = {8,4,2,1,3,6,7,15,12,20};
    Solution su;
    TreeNode *result = su.construct(A);
    vector<int> b = su.preorderTraversal(result);
    for (auto i : b) {
        cout << i << " ";
    }
    
    cout << endl;
    return 0;
}

