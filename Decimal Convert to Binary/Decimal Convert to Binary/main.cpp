//
//  main.cpp
//  Decimal Convert to Binary
//
//  Created by Shuai Wang on 11/5/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

void ConvertToBinary(int n)
{
    if (n / 2 != 0) {
        ConvertToBinary(n / 2);
    }
    printf("%d", n % 2);
}

int main(int argc, const char * argv[]) {
    ConvertToBinary(10);
    return 0;
}
