//
//  main.cpp
//  Reverse String and String Vector
//
//  Created by Shuai Wang on 10/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void reverse(vector<string *> &A) {
        if (A.size() == 0) {
            return;
        }
        
        for (int i = 0; i < A.size(); i++) {
            
            reverseStr(A[i]);
        }
        
        int start = 0;
        int end = (int)A.size() - 1;
        swap(A[start], A[end]);
        return;
        
    }
    
    void reverseStr(string *str) {
        int start = 0;
        int end = (int)str->size() - 1;
        while (start <= end) {
            char tmp = str->at(start);
            str->at(start) = str->at(end);
            str->at(end) = tmp;
            start++;
            end--;
        }
        
        return;
    }
    
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    string *a = new string("Hello, World!");
    string *b = new string ("My name is Wang");
    string *c = new string ("Here is my Home");
    string *d = new string ("Life is about happy");
    vector<string *> A = {a, b, c,d};
    Solution su;
    su.reverse(A);
    
    for (int i = 0; i < A.size(); i++) {
        cout << *A[i] << endl;
    }
    
    return 0;
}

