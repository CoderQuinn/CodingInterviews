//
//  CopyRandomList.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/17.
//

#include <stdio.h>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
    label(x), next(NULL), random(NULL) {
    }
};
    
class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* pHead) {
        if (!pHead) return nullptr;
        
        RandomListNode *curr = pHead;
        
        while (curr) {
            RandomListNode *add_node = new RandomListNode(curr->label);
            add_node->next = curr->next;
            curr->next = add_node;
            curr = curr->next->next;
        }
        
        curr = pHead;
        while (curr) {
            curr->next->random = curr->random ? curr->random->next : nullptr;
            curr = curr->next->next;
        }
        
        RandomListNode *old_ptr = pHead;
        RandomListNode *new_ptr = pHead->next;
        RandomListNode *result = new_ptr;
        
        while (old_ptr) {
            old_ptr->next = old_ptr->next->next;
            // 新链表尾指针特殊处理
            new_ptr->next = new_ptr->next ? new_ptr->next->next : nullptr;
            old_ptr = old_ptr->next;
            new_ptr = new_ptr->next;
        }
        
        return result;
    }
};
