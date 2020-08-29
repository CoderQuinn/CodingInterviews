//
//  27 mirrorTree.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stdio.h>
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
    TreeNode *bfs(TreeNode *root) {
        if (!root) return nullptr;
        
        TreeNode *left = root->left;
        root->left = bfs(root->right);
        root->right = bfs(left);
        return root;
    }
    TreeNode* mirrorTree(TreeNode* root) {
        return bfs(root);
    }
};
