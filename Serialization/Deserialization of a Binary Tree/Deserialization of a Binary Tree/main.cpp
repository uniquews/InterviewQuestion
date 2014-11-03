//
//  main.cpp
//  Deserialization of a Binary Tree
//
//  Created by Shuai Wang on 11/2/14.
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
    
    void deserialize(TreeNode *&root, vector<int> nodes, int &index) {
        if (index == nodes.size() || nodes[index] == -1) {
            index++;
            return;
        }
        
        int cur = index++;
        root = new TreeNode(nodes[cur]);
        deserialize(root->left, nodes, index);
        deserialize(root->right, nodes, index);
  
    }
    
    vector<int> preorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return vector<int> {};
        }
        
        vector<int> result;
        stack<TreeNode *> stk;
        stk.push(root);
        while (stk.size() > 0) {
            TreeNode *cur = stk.top();
            stk.pop();
            result.push_back(cur->val);
            
            if (cur->right != nullptr) {
                stk.push(cur->right);
            }
            
            if (cur->left != nullptr) {
                stk.push(cur->left);
            }
        }
        
        return result;
    }

};

int main(int argc, const char * argv[]) {
    vector<int> A = {20, 8, 4, -1, -1, 12, 10, -1, -1, 14, -1, -1, -1};
    Solution su;
    TreeNode *root = nullptr;
    int start = 0;
    su.deserialize(root, A, start);
    vector<int> result = su.preorderTraversal(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
