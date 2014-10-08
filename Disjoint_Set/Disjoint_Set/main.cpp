//
//  main.cpp
//  Disjoint_Set
//
//  Created by Shuai Wang on 10/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Disjoint_Set {
public:
    
    unordered_map<char, char> parent;
    unordered_map<char, int> rank;
    
    Disjoint_Set() {
        
        vector<char> universe = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        for (int i = 0; i < universe.size(); i++) {
            parent[universe[i]] = universe[i];
            rank[universe[i]] = 0;
        }
        
        return;
    }
    
    char find(char c) {
        if (c != parent[c]) {
            return find(parent[c]);
        } else {
            return parent[c];
        }
        
    }
    
    void UnionSet (char a, char b) {
        if (find(a) == find(b)) {
            return;
        }
        
        char p1 = find(a);
        char p2 = find(b);
        
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else if (rank[p2] > rank[p1]) {
            parent[p1] = p2;
        } else {
            parent[p1] = p2;
            rank[p2]++;
        }
        return;
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

