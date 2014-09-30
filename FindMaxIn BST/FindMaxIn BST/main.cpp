//
//  main.cpp
//  FindMaxIn BST
//
//  Created by Shuai Wang on 9/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int findMax(TreeNode *root) {
        if (root == nullptr) {
            return INT_MIN;
        }
        
        int result = INT_MIN;
        generate(root, result);
        return result;
    
    }
    
    void generate(TreeNode *node, int &result) {
        if (node == nullptr) {
            return;
        }
        
        result = max(node->val, result);
        generate(node->left, result);
        generate(node->right, result);
        return;
    
    }


};

int main(int argc, const char * argv[])
{

    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);
    
    a->left = b;
    b->right = c;
    b->left = d;
    a->right = e;
    e->left = f;
    e->right = g;
    
    Solution su;
    cout << su.findMax(a) <<endl;
    return 0;
}

