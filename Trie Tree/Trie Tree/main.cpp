//
//  main.cpp
//  Trie Tree
//
//  Created by Shuai Wang on 9/25/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>


using namespace std;

class TreeNode {
public:
    
    char val;
    list<TreeNode *> children;
    int isWord;
    TreeNode(char c) : val(c), children(NULL), isWord(0){};

};

class TrieTree{
public:
    TreeNode *root;
    TrieTree() {
        char rootVal = '\0';
        TreeNode *node = new TreeNode(rootVal);
        this->root = node;
    }
};


class Solution {
public:
    TrieTree* traverse(vector<string> words) {
        TrieTree *tree = new TrieTree();
        TreeNode *root = tree->root;
        for (int i = 0; i < words.size(); i++) {
            string cur = words[i];
            dfs(0, cur, root);
        
        
        }
    
        return tree;
    }
    
    
    void dfs(int index, string s, TreeNode *node) {
        if (index == s.size()) {
            node->isWord++;
            return;
        }
        bool found = false;
        list<TreeNode *> :: iterator it = node->children.begin();
        while (*it != nullptr) {
            
            if ((*it)->val == s[index]) {
                found = true;
                dfs(index + 1, s, *it);
                break;
            }
            it++;
        
        }
        
        if (found) {
            return;
        } else {
            TreeNode *newNode = new TreeNode(s[index]);
            node->children.push_back(newNode);
        
        }
    
    }



};


int main(int argc, const char * argv[])
{

    vector<string> str = {"abs", "abc", "ghe", "bdf"};
    Solution su;
    su.traverse(str);
    
    return 0;
}

