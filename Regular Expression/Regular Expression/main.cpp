//
//  main.cpp
//  Regular Expression
//
//  Created by Shuai Wang on 10/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <regex>

using namespace std;


//extract name reg
int main(int argc, const char * argv[])
{

    string str;
    while (true) {
        cin >> str;
        
        regex e("[[:alpha:]]+[[:s:]]+[[:alpha:]]", regex_constants::icase);
//        regex e("([A-Z][a-z]+)/s([A-Z][a-z]+)", regex_constants::icase);
//        regex e("[[:alpha:]]+", regex_constants::icase);
        bool match = regex_match(str, e);
        if (match == true) {
            cout << "Matched" << endl;
            break;
        } else{
            cout << "Not Matched" << endl;
            break;
        }
        
    }
    return 0;
}

