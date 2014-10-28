//
//  main.cpp
//  Overlap Rectangle
//
//  Created by Shuai Wang on 10/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Rect{
public:
    int x1, y1;
    int x2, y2;
    
    Rect (int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        return;
    }
};

class Solution {
public:
    Rect overlapRec (Rect r1, Rect r2) {
        vector<int> xIndex = {r1.x1, r1.x2, r2.x1, r2.x2};
        int left = INT_MAX;
        int right = INT_MIN;
        for (int i = 0; i < xIndex.size(); i++) {
            left = min(xIndex[i], left);
            right = max(xIndex[i], right);
        }
        
        int xStart = left;
        int firstX = INT_MAX;
        int secondX = INT_MAX;
        while (xStart <= right + 1) {
            if (firstX == INT_MAX && xStart >= r1.x1 && xStart <= r1.x2 && xStart >= r2.x1 && xStart <= r2.x2) {
                firstX = xStart;
            }
            
            if (firstX != INT_MAX && !(xStart >= r1.x1 && xStart <= r1.x2 && xStart >= r2.x1 && xStart <= r2.x2)) {
                secondX = xStart - 1;
                break;
            }
            
            xStart++;
        }
        
        if (firstX == INT_MAX) {
            Rect r (0,0,0,0);
            return r;
        }
        
        vector<int> yIndex = {r1.y1, r1.y2, r2.y1, r2.y2};
        int bottom = INT_MAX;
        int up = INT_MIN;
        for (int i = 0; i < yIndex.size(); i++) {
            bottom = min(yIndex[i], bottom);
            up = max(yIndex[i], up);
        }
        
        int yStart = bottom;
        int firstY = INT_MAX;
        int secondY = INT_MAX;
        while (yStart <= up + 1) {
            if (firstY == INT_MAX && yStart >= r1.y1 && yStart <= r1.y2 && yStart >= r2.y1 && yStart <= r2.y2) {
                firstY = yStart;
            }
            
            if (firstY != INT_MAX && !(yStart >= r1.y1 && yStart <= r1.y2 && yStart >= r2.y1 && yStart <= r2.y2)) {
                secondY = yStart - 1;
                break;
            }
            
            yStart++;
        }
        
        if (firstY == INT_MAX) {
            Rect r (0,0,0,0);
            return r;
        }
        
        Rect result(firstX, firstY, secondX, secondY);
        return result;
        
        
    }
    
    
    
};

int main(int argc, const char * argv[])
{

    Rect r1 = {1,2,4,5};
    Rect r2 = {0,2,2,3};
    Solution su;
    Rect result = su.overlapRec(r1, r2);
    cout << result.x1 << " " << result.y1 << " " << result.x2 << " " << result.y2 << endl;
    
    return 0;
}

