//
//  main.cpp
//  Topological Sort
//
//  Created by Shuai Wang on 10/4/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {

public:
    int val;
    vector<Node *> *neighbors;
    
    Node (int val) {
        this->val = val;
        this->neighbors = new vector<Node *> ();
    }

};


class TopologicalSort {

public:
    vector<Node *> TS (Node *node) {
        if (node == nullptr) {
            return vector<Node *> {};
            
        }
        
        vector<Node *> result;
        
        unordered_map<Node *, vector<Node *>> indegree;
        unordered_map<Node *, vector<Node *>> outdegree;
        
        
        vector<Node *> nodeList;
        unordered_set<Node *> visited;
        
        nodeList.push_back(node);
        visited.insert(node);
        
        
        //第一步，把邻居关系转换为出度入读关系
        int start = 0;
        while (start < nodeList.size()) {
            Node *cur = nodeList[start++];
            
            for (int i = 0; i < cur->neighbors->size(); i++) {
                if (visited.find(cur->neighbors->at(i)) == visited.end()) {
                    nodeList.push_back(cur->neighbors->at(i));
                    visited.insert(cur->neighbors->at(i));
                    
                }
                
                outdegree[cur].push_back(cur->neighbors->at(i));
                indegree[cur->neighbors->at(i)].push_back(cur);
                
            }
        
        }
        
        //第二步，把入度为零的开始节点和出度为0的结尾节点都加入
        for (int i = 0; i < nodeList.size(); i++) {
            if (indegree.find(nodeList[i]) == indegree.end()) {
                indegree[nodeList[i]] = {};
                
            }
            
            if (outdegree.find(nodeList[i]) == outdegree.end()) {
                outdegree[nodeList[i]] = {};
            }
        }
        
        
        
        unordered_map<Node *, vector<Node *>> :: iterator it = indegree.begin();
        while (it != indegree.end()) {
            //迭代器现在所指的未必是入读为零的节点
            bool isErase = false;

            if (it->second.size() == 0) {
                Node *ready = it->first;
                result.push_back(ready);
                
                //入度hashmap要删掉这个节点
                indegree.erase(ready);
                isErase = true;
                
                if (outdegree[ready].size() != 0) {
                    for (int i = 0; i < outdegree[ready].size(); i++) {                        
                        vector<Node *> :: iterator it2 = find(indegree[outdegree[ready][i]].begin(), indegree[outdegree[ready][i]].end(), ready);
                        indegree[outdegree[ready][i]].erase(it2);
                    
                    }
                }
                
                //出度hashmap要删掉这个节点
                outdegree.erase(ready);
            }
            
            if (isErase) {
                it = indegree.begin();
            } else {
                it++;
            }
            
        }
    
        //最后可以判断result结果集的size和nodeList的size是不是一样大，从而得出是否是有向无环图
        return result;
    
    }

};



int main(int argc, const char * argv[])
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);

    a->neighbors->push_back(b);
    a->neighbors->push_back(c);
    c->neighbors->push_back(b);
    b->neighbors->push_back(d);
    b->neighbors->push_back(e);
    d->neighbors->push_back(e);
    
    TopologicalSort su;
    vector<Node *> result = su.TS(a);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i]->val << endl;
    }

    
    
    return 0;
}

