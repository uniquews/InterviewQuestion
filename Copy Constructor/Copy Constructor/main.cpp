//
//  main.cpp
//  Copy Constructor
//
//  Created by Shuai Wang on 10/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class smartPointer {
private:
    string *m_name;
    
public:
    smartPointer (string *name) {
        m_name = name;
    }
    
    smartPointer(const smartPointer &rhs) {
        m_name = new string(*(rhs.m_name));
    }
    
    smartPointer& operator= (const smartPointer &rhs) {
        m_name = new string(*(rhs.m_name));
        return *this;
    }
    
    virtual ~smartPointer() {
        delete m_name;
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

