//
//  28 isSymmetric.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return bfs(root->left, root->right);
    }
    
    bool bfs(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right || left->val != right->val) return false;
        
        return bfs(left->left, right->right) && bfs(left->right, right->left);
    }
};

class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode *> node_queue;
        node_queue.push(root->left);
        node_queue.push(root->right);
        
        while (!node_queue.empty()) {
            TreeNode *left = node_queue.front();
            node_queue.pop();
            
            TreeNode *right = node_queue.front();
            node_queue.pop();
            
            if (!left && !right) continue; // [1,2,2,null,3,3,null] is Symmetric
            if (!left || !right || left->val != right->val) return false;
            
            node_queue.push(left->left);
            node_queue.push(right->right);
            node_queue.push(left->right);
            node_queue.push(right->left);
        }
        
        return true;
    }
    
};
