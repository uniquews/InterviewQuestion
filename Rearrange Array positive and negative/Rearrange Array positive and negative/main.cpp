//
//  main.cpp
//  Rearrange Array positive and negative
//
//  Created by Shuai Wang on 9/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    void rightrotate(int arr[], int outofplace, int cur)
    {
        char tmp = arr[cur];
        for (int i = cur; i > outofplace; i--)
            arr[i] = arr[i-1];
        arr[outofplace] = tmp;
    }
    
    
    void rearrange(int arr[], int n)
    {
        int outofplace = -1;
        
        for (int index = 0; index < n; index ++)
        {
            if (outofplace >= 0)
            {
                // find the item which must be moved into the out-of-place
                // entry if out-of-place entry is positive and current
                // entry is negative OR if out-of-place entry is negative
                // and current entry is negative then right rotate
                //
                // [...-3, -4, -5, 6...] -->   [...6, -3, -4, -5...]
                //      ^                          ^
                //      |                          |
                //     outofplace      -->      outofplace
                //
                if (((arr[index] >= 0) && (arr[outofplace] < 0))
                    || ((arr[index] < 0) && (arr[outofplace] >= 0)))
                {
                    rightrotate(arr, outofplace, index);
                    
                    // the new out-of-place entry is now 2 steps ahead
//                    if (index - outofplace > 2)
//                        outofplace = outofplace + 2;
//                    else
                        outofplace = -1;
                }
            }
            
            
            // if no entry has been flagged out-of-place
            if (outofplace == -1)
            {
                // check if current entry is out-of-place
                if (((arr[index] >= 0) && (!(index & 0x01)))
                    || ((arr[index] < 0) && (index & 0x01)))
                {
                    outofplace = index;
                }
            }
        }
    }
    
    
};

int main(int argc, const char * argv[])
{

    int A[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    Solution su;
    su.rearrange(A, 10);
    for (int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    return 0;
}

