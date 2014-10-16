//
//  main.cpp
//  Exception
//
//  Created by Shuai Wang on 10/15/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class dog {
public:
    string m_name;
    dog(string name) {m_name = name; cout << m_name << " is created." << endl;}
    ~dog() {cout << m_name << " is destroied. " << endl;}
    void bark() {cout << m_name << " bark." << endl;}

};

int main(int argc, const char * argv[])
{

    try {
        dog dog1("Herry");
        dog dog2("Bob");
//        throw 20;  // 碰到throw语句会调用析构函数清除栈空间。
        dog1.bark();
        dog2.bark();
    
    } catch (int e) {
    
    }
    return 0;
}

