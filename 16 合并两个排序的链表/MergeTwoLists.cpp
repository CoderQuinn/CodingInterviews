//
//  MergeTwoLists.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/16.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1) {
            return pHead2;
        } else if (!pHead2) {
            return pHead1;
        }
        
        ListNode *result = nullptr;
        
        if (pHead1->val < pHead2->val) {
            result = pHead1;
            result->next = Merge(pHead1->next, pHead2);
        } else {
            result = pHead2;
            result->next = Merge(pHead1, pHead2->next);
        }
        
        return result;
    }
};

class Solution2 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode dummy_node(0);
        ListNode *tail = &dummy_node;
        
        ListNode *l1 = pHead1;
        ListNode *l2 = pHead2;
        while (l1 && l2) {
            ListNode *curr = nullptr;
            if (l1->val < l2->val) {
                curr = l1;
                l1 = l1->next;
            } else {
                curr = l2;
                l2 = l2->next;
            }
            
            tail->next = curr;
            tail = curr;
            tail->next = nullptr;
        }
        
        tail->next = l1 ? l1 : l2;
        
        return dummy_node.next;
    }
};
