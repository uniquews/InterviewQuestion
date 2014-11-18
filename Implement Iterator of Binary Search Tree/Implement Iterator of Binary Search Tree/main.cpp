//
//  main.cpp
//  Implement Iterator of Binary Search Tree
//
//  Created by Shuai Wang on 11/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


class Solution {
public:
    TreeNode *start = new TreeNode(-1);
    TreeNode *current = nullptr;
    Solution(TreeNode *root) {
        // write your code here
        start->right = root;
    }
    
    
    TreeNode* inorder(TreeNode *node) {
        TreeNode *cur = node;
        TreeNode *prev = nullptr;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                this->start->right = cur->right;
                return cur;
            } else {
                prev = cur->left;
                while (prev->right != nullptr && prev->right != cur) {
                    prev = prev->right;
                }
                
                if (prev->right == nullptr) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    this->start->right = cur->right;
                    TreeNode *tmp = cur;
                    prev->right = nullptr;
                    return tmp;
                    
                }
            }
        
        }
        return nullptr;
    }

    
    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        current = inorder(this->start->right);
        if (current != nullptr) {
            return true;
        } else {
            return false;
        }
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode *tmp = current;
        return tmp;
    }


};


int main(int argc, const char * argv[]) {
    TreeNode *a = new TreeNode(8);
    TreeNode *b = new TreeNode(3);
    TreeNode *c = new TreeNode(13);
    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(4);
    TreeNode *g = new TreeNode(6);
    TreeNode *h = new TreeNode(11);
    TreeNode *i = new TreeNode(9);
    TreeNode *j = new TreeNode(12);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    e->left = f;
    e->right = g;
    c->left = h;
    h->left = i;
    h->right = j;
    
    
    
    Solution *s = new Solution(a);
    while (s->hasNext()) {
        cout << s->next()->val << endl;
    }
    return 0;
}
