//
//  EntryNodeOfLoop.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/16.
//

#include <stdio.h>

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode *slow = pHead;
        ListNode *fast = pHead;
        ListNode *meet = nullptr;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                meet = slow;
                break;
            }
        }
        
        if (!meet) return nullptr;
        
        slow = pHead;
        while (meet && slow) {
            if (meet == slow) {
                return meet;
            }
            meet = meet->next;
            slow = slow->next;
        }
        
        return nullptr;
        
    }
};
