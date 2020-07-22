//
//  FindFirstCommonNode.cpp
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode *p = headA;
        ListNode *q = headB;
        
        while (p != q) {
            p = p->next;
            q = q->next;
            if (!p && q) { // B链表较长，p先走完A
                p = headB;
            } else if(p && !q){ // A链表较长，q先走完B
                q = headA;
            } else if (!p && !p) { // 不相交
                return nullptr;
            }
        }
        return p;
    }
};
