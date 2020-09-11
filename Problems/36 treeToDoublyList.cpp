//
//  36 treeToDoublyList.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/9.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <algorithm>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node() {}
    
    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
    
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    
    Node *prev = nullptr, *head = nullptr;
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        dfs(root);
        prev->right = head;
        head->left = prev;
        return head;
    }
    
    void dfs(Node *root)
    {
        if (!root) return;
        
        dfs(root->left);
        
        if (!prev) head = root;
        else prev->right = root;
            
        root->left = prev;
        prev = root;
        
        dfs(root->right);
        
    }
};
