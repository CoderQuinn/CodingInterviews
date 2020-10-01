//
//  55 - II isBalanced.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <algorithm>
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        if (abs(left_depth - right_depth) > 1) return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// 自顶向下
class Solution1 {
public:

    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return is_balance_core(root, depth);
    }
    
    bool is_balance_core(TreeNode *root, int &depth) {
        if (!root) {
            depth = 0;
            return true;
        }
        
        int left_depth = 0;
        if(!is_balance_core(root->left, left_depth)) return false;
        
        int right_depth = 0;
        if(!is_balance_core(root->right, right_depth)) return false;
        
        if (abs(left_depth - right_depth) <= 1) {
            depth = max(left_depth, right_depth) + 1;
            return true;
        }
        return false;
    }
};

