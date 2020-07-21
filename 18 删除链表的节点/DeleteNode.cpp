//
//  DeleteNode.cpp
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
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode dummy_node(0);
        dummy_node.next = head;
        
        ListNode *ptr = head;
        ListNode *prev = &dummy_node;
        
        while (ptr) {
            if (ptr->val == val) {
                prev->next = ptr->next;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        
        ptr = dummy_node.next;
        return ptr;
    }
};
