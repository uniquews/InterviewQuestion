//
//  main.cpp
//  Trie Tree
//
//  Created by Shuai Wang on 9/30/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

const int kind = 26;

class TreeNode {
public:
    int count = 0;
    
    TreeNode *next[kind];
    TreeNode () {
        count = 1;
        for (int i = 0; i < kind; i++) {
            next[i] = NULL;
        }
        
    }

};


class TrieTree {

public:
    void insert(TreeNode *&root, vector<string> &words);
    vector<int> search(TreeNode *&root, vector<string> asks);


};


void TrieTree::insert(TreeNode *&root, vector<string> &words) {
    TreeNode *location = root;
    
    if (location == nullptr) {
        location = new TreeNode();
        root = location;
    }
    
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        int index = 0;
        int branch = 0;
        while (word[index] != '\0') {
            branch = word[index] - 'a';
            if (location->next[branch] != nullptr) {
                location->next[branch]->count++;
            } else {
                location->next[branch] = new TreeNode();
            }
            index++;
            location = location->next[branch];
        }
        
        location = root;
    }

}


vector<int> TrieTree::search(TreeNode *&root, vector<string> asks) {
    TreeNode *location = root;
   
    vector<int> results;
    
    if (location == nullptr) {
        return vector<int> {};
    }
    
    for (int i = 0; i < asks.size(); i++) {
        string ask = asks[i];
        int index = 0;
        int branch = 0;
        int result = 0;
        
        while (ask[index] != '\0' && location != nullptr) {
            branch = ask[index] - 'a';
            if (location->next[branch] == nullptr) {
                result = 0;
            } else {
                result = location->next[branch]->count;
            }
            
            index++;
            location = location->next[branch];
        }
        location = root;
        results.push_back(result);
    }
    
    return results;

}


int main(int argc, const char * argv[])
{

    vector<string> strs = {"banana", "band", "bee", "absolute", "acm"};
    vector<string> asks = {"ba", "b", "band", "abc", "bac" };

    TreeNode *root = nullptr;
    TrieTree tree;
    tree.insert(root, strs);
    vector<int> results = tree.search(root, asks);
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    return 0;
}

