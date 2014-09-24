//
//  main.cpp
//  Minimum No of iterations to pass information to all nodes in tree
//
//  Created by Shuai Wang on 9/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class TreeNode {
public:
    int val;
    list<TreeNode *> children;
    TreeNode(int x) : val(x){}
    
    void addChild(TreeNode * c) {
        this->children.push_back(c);
    }

};

class Solution {
public:
    int minPass(TreeNode *node) {
        int result = INT_MIN;
        if (node == nullptr) {
            return 0;
        }
        if (node->children.size() == 0) {
            return 0;
        }
        
        vector<int> f(node->children.size());
        
        list<TreeNode *>::iterator it = node->children.begin();
        
        for (int i = 0; it != node->children.end(); it++, i++) {
            f[i] = minPass(*it);
        }
        
        sort(f.begin(), f.end());
        unordered_map<int, int> exist;
        for (int i = 0; i < f.size(); i++) {
            exist[f[i]]++;
            
        }
        
        for (int i = 0; i < f.size(); i++) {
            result = max(result, f[i] + (int)f.size() - i);
        }
        
        return result;
    
    }

};

int main(int argc, const char * argv[])
{
//    TreeNode *a = new TreeNode (0);
//    TreeNode *b = new TreeNode (1);
//    TreeNode *c = new TreeNode (2);
//    TreeNode *d = new TreeNode (3);
//    
//    TreeNode *e = new TreeNode (4);
//    TreeNode *f = new TreeNode (5);
//    TreeNode *g = new TreeNode (6);
//    TreeNode *h = new TreeNode (7);
//    
//    TreeNode *i = new TreeNode (8);
//    TreeNode *j = new TreeNode (9);
//    TreeNode *k = new TreeNode (10);
//    TreeNode *l = new TreeNode (11);
//    
//    TreeNode *m = new TreeNode (12);
//    TreeNode *n = new TreeNode (13);
//    TreeNode *o = new TreeNode (14);
//    TreeNode *p = new TreeNode (15);
//    
//    TreeNode *q = new TreeNode (16);
    
//    a->addChild(b);
//    a->addChild(c);
//    a->addChild(d);
//    a->addChild(e);
//    a->addChild(f);
//    a->addChild(g);
//    
//    b->addChild(h);
//    b->addChild(i);
//    b->addChild(j);
//    
//    e->addChild(k);
//    e->addChild(l);
//    
//    g->addChild(m);
//    
//    h->addChild(n);
//    h->addChild(o);
//    
//    k->addChild(p);
//    
//    l->addChild(q);
    
    
    
    
    
    TreeNode *a = new TreeNode (0);
    TreeNode *b = new TreeNode (1);
    TreeNode *c = new TreeNode (2);
    TreeNode *d = new TreeNode (3);
    
    TreeNode *e = new TreeNode (4);
    TreeNode *f = new TreeNode (5);
    TreeNode *g = new TreeNode (6);
    TreeNode *h = new TreeNode (7);
    
    TreeNode *i = new TreeNode (8);
    TreeNode *j = new TreeNode (9);
    TreeNode *k = new TreeNode (10);
    TreeNode *l = new TreeNode (11);
    
    TreeNode *m = new TreeNode (12);
    TreeNode *n = new TreeNode (13);
    
    
    a->addChild(b);
    a->addChild(c);
    a->addChild(d);
    a->addChild(e);
    
    
    b->addChild(f);
    c->addChild(g);
    c->addChild(h);
    
    d->addChild(i);
    d->addChild(j);
    d->addChild(k);
    
    e->addChild(l);
    
    e->addChild(m);
    e->addChild(n);
    
    
    Solution su;
    cout << su.minPass(a) <<endl;

    
    return 0;
}

