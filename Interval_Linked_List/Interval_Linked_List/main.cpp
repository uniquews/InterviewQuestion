//
//  main.cpp
//  Interval_Linked_List
//
//  Created by Shuai Wang on 9/13/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    
public:
    ListNode* intervalLinkedList(ListNode *p, ListNode* q) {
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        while (p != nullptr || q != nullptr) {
            ListNode *nextP = p == nullptr ? nullptr : p -> next;
            ListNode *nextQ = q == nullptr ? nullptr : q -> next;
            
            if (p == nullptr) {
                prev -> next = q;
                prev = prev -> next;
                q = nextQ;
            } else if (q == nullptr) {
                prev -> next = p;
                prev = prev -> next;
                p = nextP;
            } else {
                prev -> next = p;
                p -> next = q;
                prev = q;
                p = nextP;
                q = nextQ;
                
            }
            
            
        }
        
        
        return dummy.next;
        
        
    }
    
    
};

int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode (1);
    ListNode *b = new ListNode (2);
    ListNode *c = new ListNode (3);
    
    ListNode *d = nullptr;
//    ListNode *e = new ListNode (6);
//    ListNode *f = new ListNode (7);
//    ListNode *g = new ListNode (8);

    
    
    a -> next = b;
    b -> next = c;
    
//    d -> next = e;
//    e -> next = f;
//    f -> next = g;

    Solution su;
    ListNode *result = su.intervalLinkedList(a, d);
    
    while (result != nullptr) {
        cout << result -> val << " ";
        result = result -> next;
    
    }
    
    return 0;
}

