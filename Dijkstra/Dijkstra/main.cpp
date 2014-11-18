//
//  main.cpp
//  Dijkstra
//
//  Created by Shuai Wang on 11/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void dijkstra(vector<vector<int>> &G, int source) {
        vector<int> previous(G.size());
        vector<int> dist(G.size());
        vector<bool> visited(G.size());
        priority_queue<int, vector<int>, greater<int>> q;
        
        dist[0] = 0;
        for (int i = 0; i < G.size(); i++) {
            if (i != 0) {
                dist[i] = INT_MAX;
                previous[i] = NULL;
            }
            q.push(dist[i]);
        }
        
        while (q.size() != 0) {
            int v = q.top();
            q.pop();
            visited
            
        }
    
    }


};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
