//
//  55 - I maxDepth.cpp
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
};

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        bfs(root, 0, ans);
        return ans;
    }
    
    void bfs(TreeNode *root, int depth, int &ans) {
        if (!root) return;
        
        if (!root->left &&!root->right) {
            ans = max(ans, depth + 1);
            return;
        }
        
        bfs(root->left, depth + 1, ans);
        bfs(root->right, depth + 1, ans);
    }
};
