//
//  18 deleteNode.cpp
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *curr = head;
        ListNode *prev = dummy;
        while (curr) {

            if (curr->val == val) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        curr->next = nullptr;
        return dummy->next;
    }
};
