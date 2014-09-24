//
//  main.cpp
//  Build Tallest People
//
//  Created by Shuai Wang on 9/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int buildTallestTower(vector<vector<int>> &people) {
//        if (people.size() == 0) {
//            return 0;
//        }
//        
//        vector<int> f (people.size());
//        int maxHeight = 0;
//        
//        for (int i = 0; i < people.size(); i++) {
//            f[i] = people[i][1];
//            if (i > 0) {
//                if (people[i - 1][1] <= people[i][1]&& people[i - 1][0] <= people[i][0]) {
//                    f[i] += f[i - 1];
//                }
//            }
//    
//            maxHeight = max(maxHeight, f[i]);
//            
//        }
//        
//        return maxHeight;
//        
//    }
//    
//    
//};



class Solution {
    
public:
    
    int buildTallestTower2(vector<vector<int>> &people) {
        if (people.size() == 0) {
            return 0;
        }
        
        vector<int> f(people.size());
        int maxNum = 1;
        quicksort(people, 0, (int)people.size() - 1);
        
        
        for (int i = 0; i < people.size(); i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++) {
                if (people[j][0] <= people[i][0]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            
            maxNum = max(maxNum, f[i]);
        }
        
        return maxNum;
        
    }
    
    void quicksort(vector<vector<int>> &people, int left, int right) {
        int partitionIndex = partition(people, left, right);
        
        if (left < partitionIndex - 1) {
            quicksort(people, left, partitionIndex -1);
            
        }
        
        if (partitionIndex < right) {
            quicksort(people, partitionIndex, right);
        }
        
        
        return;
    }
    
    
    int partition(vector<vector<int>> &people, int left, int right) {
        int pivot = people[left + (right - left) / 2][1];
        while (left <= right) {
            while (people[left][1] < pivot) {
                left++;
            }
            
            while (people[right][1] > pivot) {
                right--;
            }
            
            if (left <= right) {
                swap(people, left, right);
                left++;
                right--;
            }
            
        }
        
        return left;
    }
    
    
    void swap(vector<vector<int>> &people, int left, int right) {
        vector<int> tempPeople = people[left];
        people[left] = people[right];
        people[right] = tempPeople;
        return;
        
    }
    
};

int main(int argc, const char * argv[])
{

    vector<vector<int>> people = {{65, 60},{70, 150},{56, 90},{75, 190},{60, 95},{68, 110},{35, 65},{40, 60},{45, 63}};
    
    Solution su;
    cout << su.buildTallestTower2(people) << endl;
    return 0;
}

