//
//  22 getKthFromEnd.cpp
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

class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *slow = dummy;
        ListNode *fast = dummy;
        // 倒数n - k + 1个
        for (int i = 0; i < k; i++) // 前进了k次
        {
            if (fast)
            {
                fast = fast->next;
            }
            else
            {
                return nullptr; // n < k
            }
        }

        if (!fast) // n < k
        {
            return nullptr;
        }

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
