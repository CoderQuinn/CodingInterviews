//
//  68 - I lowestCommonAncestor.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        if (!p) return q;
        if (!q) return p;

        if ((p->val > root->val && q->val < root->val)  || (p->val < root->val && q->val > root->val)) {
            return root;
        }
        
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return lowestCommonAncestor(root->left, p, q);
    }
};

class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *curr = root;
        while (curr) {
            if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            } else if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            } else {
                return curr;
            }
        }
        
        return nullptr;
    }
};
