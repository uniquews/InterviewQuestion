//
//  main.cpp
//  Implement a strtok
//
//  Created by Shuai Wang on 10/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
public:
//    vector<string> strtok1(string &str, string &comp) {
//        vector<string> result;
//        int start = 0;
//        while (isToken(str[start], comp)) {
//            start++;
//        }
//        
//        int end = start;
//        while (end < str.size()) {
//            if (isToken(str[end], comp)) {
//                string tmp = str.substr(start, end - start);
//                result.push_back(tmp);
//                while (end < str.size() && isToken(str[end], comp)) {
//                    end++;
//                }
//                start = end;
//            } else {
//                end++;
//            }
//        }
//        
//        return result;
//        
//    }
//    
//    bool isToken(char c, string &comp) {
//        for (int i = 0; i < comp.size(); i++) {
//            if (c == comp[i]) {
//                return true;
//            }
//        }
//        
//        return false;
//    
//    }
    
    char * strtok1(char *s1, const char *delimit)
    {
        static char *lastToken = NULL; /* UNSAFE SHARED STATE! */
        char *tmp;
        
        /* Skip leading delimiters if new string. */
        if ( s1 == NULL ) {
            s1 = lastToken;
            if (s1 == NULL)         /* End of story? */
                return NULL;
        }
        
        size_t len = strspn(s1, delimit);
        s1 += len; //跨过s1中 所以的delimit
        
        
        /* Find end of segment */
        tmp = strpbrk(s1, delimit); // 找到了第一个segment使得这个segement里所有的char 都符合delimit
        if (tmp) {
            /* Found another delimiter, split string and save state. */
            *tmp = '\0';
            lastToken = tmp + 1;
        } else {
            /* Last segment, remember that. */
            lastToken = NULL;
        }
        
        return s1;
    }
    
};

int main(int argc, const char * argv[])
{
    
//    Solution su;
//    string str ="- This,       a sample string    .";
//    string token = " ,.-";
//    vector<string> result = su.strtok1(str, token);
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i] << endl;
//    }
    Solution su;
    char str[] ="- This, a sample string.";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = su.strtok1 (str," ,.-");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = su.strtok1 (NULL, " ,.-");
    }
    return 0;
    
}

