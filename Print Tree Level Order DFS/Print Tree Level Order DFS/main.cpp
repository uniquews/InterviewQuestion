//
//  main.cpp
//  Print Tree Level Order DFS
//
//  Created by Shuai Wang on 10/12/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrdere(TreeNode *root) {
        if (root == nullptr) {
            return vector<vector<int>> {};
        }
        
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
    
    
    void dfs(TreeNode *node, int level, vector<vector<int>> &result) {
        if (node == nullptr) {
            return;
        }
        
        if ((int)result.size() - 1 < level) {
            vector<int> level;
            level.push_back(node->val);
            result.push_back(level);
        } else {
            result[level].push_back(node->val);
        }
        
        dfs(node->left, level + 1, result);
        dfs(node->right, level + 1, result);
        
        return;
        
    }
    
    
};

int main(int argc, const char * argv[])
{

    Solution su;
    
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);
    TreeNode *h = new TreeNode(8);
    TreeNode *i = new TreeNode(9);
    TreeNode *j = new TreeNode(10);
    
    a->left = b;
    a->right = c;
    b->left = g;
    b->right = f;
    g->left = h;
    g->right = i;
    c->right = d;
    d->left = e;
    e->left = j;
    
    vector<vector<int>> result;
    result = su.levelOrdere(a);
    
    for (auto v : result) {
        for (auto i : v) {
            cout << i << " ";
        }
        
        cout << endl;
    }
    return 0;
}

