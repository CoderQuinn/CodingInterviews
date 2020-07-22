//
//  ReverseList.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/16.
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *ptr = nullptr;
        ListNode *curr = pHead;
        
        while (curr) {
            ListNode *next = curr->next;
            curr->next = ptr;
            ptr = curr;
            curr = next;
        }
        
        return ptr;
    }
};
