//
//  24 reverseList.cpp
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
    ListNode* reverseList(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;

        while (head) {
            ListNode *tmp = head;
            tmp = tmp->next;
            
            head->next = curr->next;
            curr->next = head;
            
            head = tmp;
        }
        
        return dummy->next;
    }
};
