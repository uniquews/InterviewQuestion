//
//  main.cpp
//  Next Largest Node in BST
//
//  Created by Shuai Wang on 9/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        vector<int> eachLevel;
        vector<vector<int>> :: iterator it = result.begin();
        queue<TreeNode *> nodeList;
        nodeList.push(root);
        int currentLayer = 1;
        int nextLayer = 0;
        
        while (nodeList.size() != 0) {
            TreeNode *tmp = nodeList.front();
            nodeList.pop();
            eachLevel.push_back(tmp);
            currentLayer--;
            
            if (tmp->left != nullptr) {
                nodeList.push(tmp->left);
                nextLayer++;
            }
            
            if (tmp->right != nullptr) {
                nodeList.push(tmp->right);
                nextLayer++;
            }
            
            if (current == 0) {
                result.insert(it, eachLevel);
                eachLevel.clear();
                currentLayer = nextLayer;
                nextLayer = 0;
                it = result.begin();
            }
        }
        
        return result;
    }
};


//class Solution {
//public:
//    
//    TreeNode *nextLargestNode(TreeNode *root, TreeNode *p) {
//        if (root == nullptr) {
//            return nullptr;
//        }
//        
//        //先检查自己右孩子子树中最左的孩子
//        
//        if (p->right != nullptr) {
//            TreeNode *tmp = p->right;
//            while (tmp->left != nullptr) {
//                tmp = tmp->left;
//            }
//            return tmp;
//        }
//        
//        
//        //如果没有右孩子，则查看自己是不是别人的左孩子，返回父亲
//        if (p->parent != nullptr && p->parent->left == p) {
//            return p->parent;
//        }
//        
//
//        //自己是父亲的右孩子，并且自己没有右孩子，就要看自己的祖先是不是属于别人的左孩子，返回那个祖先
//        if (p->parent != nullptr) {
//            TreeNode *tmp = p->parent;
//            while (tmp->parent != nullptr) {
//                if (tmp->parent->left == tmp) {
//                    return tmp->parent;
//                }
//                tmp = tmp->parent;
//            }
//            return nullptr;
//        } else {
//            return nullptr;
//        }
//    
//    }
//
//
//};

int main(int argc, const char * argv[])
{

    
    TreeNode *a = new TreeNode(10);
    TreeNode *b = new TreeNode(4);
    TreeNode *c = new TreeNode(18);
    
    TreeNode *d = new TreeNode(2);
    TreeNode *e = new TreeNode(7);
    TreeNode *f = new TreeNode(15);
    TreeNode *g = new TreeNode(25);
    
    TreeNode *h = new TreeNode(1);
    TreeNode *i = new TreeNode(3);
    TreeNode *j = new TreeNode(9);
    TreeNode *k = new TreeNode(11);
    TreeNode *l = new TreeNode(16);
    TreeNode *m = new TreeNode(20);
    TreeNode *n = new TreeNode(30);
    
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    
    d->left = h;
    d->right = i;
    e->right = j;
    f->left = k;
    f->right = l;
    g->left = m;
    g->right = n;
    
    
    c->parent = a;
    b->parent = a;
    
    d->parent = b;
    e->parent = b;
    
    h->parent = d;
    i->parent = d;
    
    j->parent = e;
    
    f->parent = c;
    g->parent = c;
    
    k->parent = f;
    l->parent = f;
    m->parent = g;
    n->parent = g;
    
    
    Solution su;
//    TreeNode *result = su.nextLargestNode(a, h) ;
//    TreeNode *result = su.nextLargestNode(a, j) ;
//    TreeNode *result = su.nextLargestNode(a, b) ;
    TreeNode *result = su.nextLargestNode(a, k) ;
    if (result == nullptr) {
        cout << 0 << endl;
    } else {
        cout << result->val << endl;
    }
    return 0;
}

