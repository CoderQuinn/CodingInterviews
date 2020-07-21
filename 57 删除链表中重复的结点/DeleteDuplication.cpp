//
//  DeleteDuplication.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/16.
//

#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
/*
 1-1-1-1-2
 1-1-1-1-1
 */
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head)
    {
        if (!head) return nullptr;
        
        ListNode *dummy_node = new ListNode(-1);
        dummy_node->next = head;
        
        ListNode *prev = dummy_node;
        ListNode *curr = head;
        ListNode *deleted_node = nullptr;
        
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                //删除重复的结点
                ListNode *fast = curr->next;
                while (fast->next && fast->next->val == curr->val) {
                    deleted_node = fast;
                    fast = fast->next;
                    delete deleted_node;
                }
                
                deleted_node = fast;
                prev->next = fast->next;
                delete deleted_node;
                
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }

        }
        
        head = dummy_node->next;
        delete dummy_node;
        
        return head;
    }
};
