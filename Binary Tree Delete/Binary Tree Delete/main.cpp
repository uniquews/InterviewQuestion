//
//  main.cpp
//  Binary Tree Delete
//
//  Created by Shuai Wang on 11/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinarySearchTree {
public:
    TreeNode *root = nullptr;
    BinarySearchTree(TreeNode *node) {
        this->root = node;
    }
    
    void deleteNode (TreeNode *node) {
        deleteHelper(root, node);
        return;
    }
    
    void deleteHelper(TreeNode *p, TreeNode *node) {
        if (p->val == node->val) {
            if (p->left == nullptr && p->right == nullptr) {
                if (p->parent->left == node) {
                    p->parent->left = nullptr;
                } else {
                    p->parent->right = nullptr;
                }
                delete p;
                p = nullptr;
                return;
            } else if (p->right == nullptr) {
                TreeNode *tmp = p->left;
                p->val = tmp->val;
                p->left = tmp->left;
                p->right = tmp->right;
                delete tmp;
                return;
            } else if (p->left == nullptr) {
                TreeNode *tmp = p->right;
                p->val = tmp->val;
                p->left = tmp->left;
                p->right = tmp->right;
                delete tmp;
                return;
            } else {
                TreeNode *q = p;
                TreeNode *s = q->left;
                while (s->right != nullptr) {
                    q = s;
                    s = s->right;
                }
                p->val = s->val;
                if (q != p) {
                    q->right = s->left;
                } else {
                    q->left = s->left;
                }
                delete s;
                return;
            }
            
        } else if (p->val > node->val) {
            deleteHelper(p->left, node);
            return;
        } else {
            deleteHelper(p->right, node);
            return;
        }
        
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorder(root, result);
        
        return result;
    }
    
    
    
    void inorder(TreeNode *root, vector<int> &result){
        if(root==nullptr)
            return;
        if(root->left) inorder(root->left, result);
        result.push_back(root->val);
        if(root->right) inorder(root->right, result);
        
        return;
    }
};
int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(15);
    TreeNode *a = new TreeNode(5);
    TreeNode *b = new TreeNode(16);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(12);
    TreeNode *e = new TreeNode(20);
    TreeNode *f = new TreeNode(10);
    TreeNode *g = new TreeNode(13);
    TreeNode *h = new TreeNode(18);
    TreeNode *i = new TreeNode(23);
    TreeNode *j = new TreeNode(6);
    TreeNode *k = new TreeNode(8);
    TreeNode *l = new TreeNode(7);
    
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->right = e;
    d->left = f;
    d->right = g;
    f->left = j;
    j->right = k;
    e->left = h;
    e->right = i;
    k->left = l;
    
    a->parent = root;
    b->parent = root;
    c->parent = a;
    d->parent = a;
    e->parent = b;
    f->parent = d;
    g->parent = d;
    j->parent = f;
    k->parent = j;
    h->parent = e;
    i->parent = e;
    l->parent = k;

    
    
    BinarySearchTree t(root);
    TreeNode *node = new TreeNode(15);
    TreeNode *node2 = new TreeNode(16);
    t.deleteNode(node);
    t.deleteNode(node2);
    vector<int> result = t.inorderTraversal(t.root);
    int total = 0;
    for (auto i : result) {
        cout << i << " ";
        total++;
    }
    cout <<"Num of nodes: "<< total;
    cout << endl;
    
    return 0;
}
