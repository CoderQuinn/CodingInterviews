//
//  52 getIntersectionNode.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
             return nullptr;
         }
         
         ListNode *p = headA;
         ListNode *q = headB;
         
         while (p || q) {
             if (!p) {
                 p = headB;
             }
             
             if (!q) {
                 q = headA;
             }
             
             if (p == q) {
                 break;
             }
             p = p->next;
             q = q->next;
         }
         
         return p;
    }
};
