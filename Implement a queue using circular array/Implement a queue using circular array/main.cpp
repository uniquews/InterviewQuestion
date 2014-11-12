//
//  main.cpp
//  Implement a queue using circular array
//
//  Created by Shuai Wang on 11/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Myqueue {
    
private:
    int capacity;
    vector<int> arr;
    int r = 0;
    int f = 0;
    /*
     arr的size是capacity + 1;
     计算size:
        如果r比f大，之间减
        如果r比f小 (capacity - f + 1 + r)
     判断full的条件是：r - f == capacity or r - f = -1
     判断empty的条件是r == f
     
     */
public:
    
    

};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
