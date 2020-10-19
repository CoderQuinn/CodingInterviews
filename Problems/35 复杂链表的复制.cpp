//
//  35 copyRandomList.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stdio.h>

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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // 1. copy
        Node *curr = head;
        while (curr) {
            Node *tmp = curr;
            tmp = tmp->next;
            
            Node *node = new Node(curr->val);
            node->next = curr->next;
            curr->next = node;
            
            curr = tmp;
        }
        
        // 2. update random
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            
            curr = curr->next->next;
        }
        
        // 3. separate
        Node *res = head->next;
        
        Node *new_node = res;
        Node *old_node = head;
        
        while (old_node) {
            Node *old_next = old_node->next->next;
            old_node->next = old_next;
            
            new_node->next = old_next ? old_next->next : nullptr;
            new_node = new_node->next;
            
            old_node = old_next;
        }
        
        return res;
    }
};
