//
//  main.cpp
//

//
//  Created by Shuai Wang on 9/9/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


int main(int argc, const char * argv[])
{
    
    string tmp = "101010, afheoiheos";
    string::size_type sz;
    int i = stoi(tmp, &sz);
    cout << i << "......" << tmp.substr(sz) << endl;
    
    return 0;
}

