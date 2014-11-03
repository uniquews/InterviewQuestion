//
//  main.cpp
//  Check Palindrome Linkedlist
//
//  Created by Shuai Wang on 11/2/14.
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
    
    bool isPP(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        
        ListNode *first = head;
        ListNode *second = findMiddle(head);
        second = reverse(second);
        while (first != nullptr && second != nullptr) {
            if (first->val != second->val) {
                return false;
            }
            
            first = first->next;
            second = second->next;
            
        }
        return true;
    }
    
    ListNode * findMiddle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr &&  fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode dummy(-1);
        ListNode *prepare = &dummy;
        ListNode *prev = head;
        ListNode *cur = head->next;
        while (cur != nullptr) {
            prev->next = cur->next;
            cur->next = prepare->next;
            prepare->next = cur;
            cur = prev->next;
        }
        return dummy.next;
        
    }
    
};

int main(int argc, const char * argv[]) {
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *m = new ListNode(5);
    ListNode *d = new ListNode(3);
    ListNode *e = new ListNode(2);
    ListNode *f = new ListNode(1);
    
    a->next = b;
    b->next = c;
    c->next = m;
    m->next = d;
    d->next = e;
    e->next = f;
    
    
    Solution su;
    cout << su.isPP(a) << endl;
    return 0;
}
