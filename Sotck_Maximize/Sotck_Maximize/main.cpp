//
//  main.cpp
//  Sotck_Maximize
//
//  Created by Shuai Wang on 9/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

#include <iostream>
#include <vector>

using namespace std;

//int stock (vector<int> prices) {
//    if (prices.size() == 0) {
//        return 0;
//    }
//    int start = 0;
//    int index = start;
//    vector<int> increase;
//    int result = 0;
//    while (index < prices.size()) {
//        
//        while (index + 1 < prices.size() && prices[index + 1] < prices[index]) {
//            index++;
//        }
//        
//        int lengthOfIncrease = 1;
//        
//        while (index + 1 < prices.size() && prices[index] < prices[index + 1]) {
//            index++;
//            lengthOfIncrease++;
//        }
//        int tmp = 0;
//        if (lengthOfIncrease > 1) {
//            for (int i = index - 1; i >= start; i--) {
//                tmp += prices[index] - prices[i];
//            }
//            
//            result += tmp;
//            start = index + 1;
//            index = index + 1;
//            
//            
//            while (index + 1 < prices.size() && prices[index + 1] < prices[index]) {
//                index++;
//            }
//            
//        } else {
//            index++;
//        }
//        
//        
//    }
//    
//    return result;
//    
//}

int stock (vector<int> prices) {
    if (prices.size() == 0) {
        return 0;
    }
    vector<int> rightMax(prices.size());
    int _max = prices[prices.size() - 1];
    for (int i = prices.size() - 1; i >= 0; i--) {
        _max = max(_max, prices[i]);
        rightMax[i] = _max;
    }
    
    int result = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (rightMax[i] > prices[i]) {
            result += rightMax[i] - prices[i];
        }
    }
    
    return result;
    
}



int main(){
    
    int numOfTest;
    cin >> numOfTest;
    for (int i = 0; i < numOfTest; i++) {
        int numOfDays;
        cin >> numOfDays;
        vector<int> prices;
        for (int j = 0; j < numOfDays; j++) {
            int p;
            cin >> p;
            prices.push_back(p);
        }
        cout << stock(prices) << endl;
    }
    
    vector<int> prices = {1,2,100};
    cout << stock(prices) << endl;
    
}
