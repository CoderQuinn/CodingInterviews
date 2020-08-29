//
//  06 reversePrint.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// head insert
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        ListNode *dummy_node = new ListNode(-1);
        
        ListNode *p = dummy_node;
        ListNode *curr = head;
        
        while (curr) {
            ListNode *tmp = curr;
            tmp = tmp->next;
            
            curr->next = p->next;
            p->next = curr;

            curr = tmp;
        }
        
        curr = dummy_node->next;
        while (curr) {
            ans.push_back(curr->val);
            curr = curr->next;
        }
        
        return ans;
    }
    
};

// recurision
class Solution1 {
public:

    vector<int> res;
    vector<int> reversePrint(ListNode* head) {

        if (!head) {
            return res;
        } else {
            reversePrint(head->next);
            res.push_back(head->val);
        }
        return res;
    }
};
