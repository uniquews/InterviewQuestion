//
//  main.cpp
//  Inheritance
//
//  Created by Shuai Wang on 10/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Dog {
public:
    Dog() {
        cout <<  "Dog constructor" << endl;
    }
    
    virtual ~Dog() {
        cout << "Dog destructor" << endl;
    }

};


class YellowDog :public Dog {
public:
    YellowDog() {
        cout <<  "YellowDog constructor" << endl;
    }
    
    virtual ~YellowDog() {
        cout << "YellowDog destructor" << endl;
    }
    
};

int main(int argc, const char * argv[])
{

//    YellowDog y; // 没有virtual也可以正常运行
    Dog * d = new YellowDog(); // 没有virtual就不能正常运行
    delete d;
    return 0;
}

