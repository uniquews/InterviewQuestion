//
//  main.cpp
//  Parsing Arithmetic Expressions
//
//  Created by Shuai Wang on 11/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    unordered_map<char, int> p;
    p.insert({{'+', 1}});
    
    std::unordered_map<std::string,double>
    myrecipe,
    mypantry = {{"milk",2.0},{"flour",1.5}};

    
    
    int parse(vector<string> &tokens) {
        stack<int> num;
        stack<char> opt;
        int start = 0;
        
        while (start < tokens.size()) {
            if ((tokens[start][0] >= '0' && tokens[start][0] <= '9') || (tokens[start][0] == '-' && tokens[start][1] >= '0' && tokens[start][1] <= '9')) {
                int tmpNum = stoi(tokens[start]);
                start++;
            } else if (tokens[start][0] == '(') {
                opt.push(tokens[start][0]);
            } else if (tokens[start][0] == ')') {
                while (num.size() != 0 && opt.size() != 0 && opt.top() != '(') {
                    int number1 = num.top();
                    int number2 = num.top();
                    char c = opt.top();
                    opt.pop();
                    int tmp = doOperation(number2, number1, c);
                    num.push(tmp);
                
                }
                
                opt.pop();
                start++;
            } else if (tokens[start][0] == )
        
        }
        
    }

    int doOperation(int number1, int number2, char c) {
        if (c == '+') {
            return number1 + number2;
        } else if (c == '-'){
            return number1 - number2;
        } else if (c == '*') {
            return number1 * number2;
        } else {
            return number1 / number2;
        }
    
    }

};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
