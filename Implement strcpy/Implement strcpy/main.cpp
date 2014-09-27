//
//  main.cpp
//  Implement strcpy
//
//  Created by Shuai Wang on 9/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    char * strcpy( char *strDest, const char *strSrc )
    {
        //将源字符串加const，表明其为输入参数，加2分
        if( (strDest == NULL) || (strSrc == NULL)) {
            return nullptr;
        }
        
        if(strDest == strSrc) { return strDest; }
        
        char *address = strDest;
        while(*strSrc != '0') {
            *strDest = *strSrc;
            strDest++;
            strSrc++;
        }
        return address;
        
    }

};

int main(int argc, const char * argv[])
{

    char *src = "abc";
    char *dest = new char;
    Solution su;
    su.strcpy(dest, src);
    char *c = su.strcpy(dest, src);
    delete su.strcpy(dest, src);
    
    printf("%s\n",dest);
    return 0;
}

