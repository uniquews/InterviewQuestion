//
//  main.cpp
//  Binary to Decimal
//
//  Created by Shuai Wang on 11/5/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

int convertBinaryToDecimal (long n) {
    long dec = 0, rem, base = 1;
    
    while (n > 0)
    {
        rem = n % 10;
        dec = dec + rem * base;
        base = base * 2;
        n = n / 10;
    }
    cout << "The decimal equivalent of " << n << " : " << dec << endl;
    return 0;

}

int main(int argc, const char * argv[]) {
    long n = 1000;
    convertBinaryToDecimal(n);
    return 0;
}
