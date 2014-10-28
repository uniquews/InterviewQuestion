//
//  main.cpp
//  Convert tree to linked list
//
//  Created by Shuai Wang on 10/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//    
//public:
//    
//    ListNode *convertToLinkedlist(TreeNode *root) {
//        if (root == nullptr) {
//            return nullptr;
//        }
//        
//        ListNode dummy(-1);
//        ListNode *prev = &dummy;
//        traverse(root, prev);
//        return dummy.next;
//    }
//    
//    void traverse(TreeNode *root, ListNode *&last) {
//        if (root == nullptr) {
//            return;
//        }
//        
//        traverse(root->left, last);
//        last->next = new ListNode(root->val);
//        last = last->next;
//        traverse(root->right, last);
//        
//        return;
//    }
//    
//    
//};

class Solution {
    
public:
    
    ListNode *convertToLinkedlist(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (stk.size() != 0 || cur != nullptr) {
            if (cur == nullptr) {
                cur = stk.top();
                stk.pop();
                prev->next = new ListNode(cur->val);
                prev = prev->next;
                cur = cur->right;
                
            } else {
                stk.push(cur);
                cur = cur->left;
            
            }
        
        }
      return dummy.next;
    }

    
    
};


int main(int argc, const char * argv[])
{

    TreeNode *a = new TreeNode (1);
    TreeNode *b = new TreeNode (2);
    TreeNode *c = new TreeNode (3);
//    TreeNode *d = new TreeNode (4);
//    TreeNode *e = new TreeNode (5);
//    TreeNode *f = new TreeNode (6);
//    TreeNode *g = new TreeNode (7);
//    TreeNode *h = new TreeNode (8);
//    TreeNode *i = new TreeNode (9);
    
    
    a->left = b;
    a->right = c;
    
//    b->left = d;
//    b->right = e;
//    
//    d->left = h;
//    d->right = i;
//    
//    c->left = f;
//    c->right = g;
//    
    Solution su;
    ListNode *result = su.convertToLinkedlist(a);
    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next;
    }
    
    return 0;
}

