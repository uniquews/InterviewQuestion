//
//  main.cpp
//  Implement Queue using array
//
//  Created by Shuai Wang on 10/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace  std;

class Queue {
public:
    int capacity;
    vector<int> arr;
    int f;
    int r;
    
    Queue (int capacity) {
        this->capacity = capacity;
        arr.resize(capacity);
        f = -1;
        r = -1;
    }
    
    bool empty() {
        if ((r == -1 && f == -1) || (f - r) == 0) {
            return true;
        }
        
        return false;
    }
    
    bool isFull() {
        if ((r -f) == 0 || r - f == capacity) {
            return true;
        }
        
        return false;
    }
    
    size_t size() {
        if (r == -1) {
            return 0;
        } else if (r > f){
            return r - f + 1;
        } else {
            return capacity - f + r + 1;
        }
    }
    
    void enqueue(int element) {
        if (isFull()) {
            return;
        }
        
        r = (r + 1) % capacity;
        arr[r] = element;
        
        return;
    }
    
    int dequeue() {
        if (empty()) {
            return -1;
        }
        
        f = (f + 1) % capacity;
        int result =  arr[f];
        
        return result;
    }
    
};

int main(int argc, const char * argv[])
{

    Queue su(5);
    su.enqueue(1);
    su.enqueue(2);
    su.enqueue(3);
    su.enqueue(4);
    
    while (su.size() > 0) {
        cout << su.dequeue() << endl;
    
    }
    return 0;
}

