//
//  FindKthToTail.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/16.
//

#include <stdio.h>

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k == 0) return nullptr;
        
        ListNode *slow = pListHead;
        ListNode *fast = pListHead;

        while (--k) {
            if (fast->next) {
                fast = fast->next;
            } else {
                return nullptr;
            }
        }
        
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
