//
//  main.cpp
//  Find and delete second large node in BST
//
//  Created by Shuai Wang on 10/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void FindAndDelete(TreeNode * root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        
        TreeNode *last = root;
        traverse(root, last);
        return;
    
    }
    
    void traverse(TreeNode *node, TreeNode *&last) {
        if (node->left == nullptr) {
            deleteNode(node, node->right); // (parent, deltetedNode)
            return;
        }
    
    }
    

};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

