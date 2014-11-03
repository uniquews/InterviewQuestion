//
//  main.cpp
//  ReadBSTFromFile
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

using namespace std;

class Solution {

public:
    
    void readBST(TreeNode *&root, vector<int> &nodes) {
        int start = 0;
        helper(root, nodes, INT_MIN, INT_MAX, start);
        return;
    }
    
    void helper(TreeNode *&p, vector<int> &nodes, int _min, int _max, int &index) {
        if (nodes[index] > _min && nodes[index] < _max) {
            int cur = index;
            p = new TreeNode(nodes[index++]);
            if (index < nodes.size()) {
                
                helper(p->left, nodes, _min, nodes[cur], index);
                helper(p->right, nodes, nodes[cur], _max, index);
            }
        
        }
        return;
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
    TreeNode *root = nullptr;
    vector<int> nodes = {30, 20, 10, 40, 35, 50};
    Solution su;
    su.readBST(root, nodes);
    vector<int> result = su.preorderTraversal(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
