//
//  54 二叉搜索树的第k大节点.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/18.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stdio.h>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode *u, int &k, int &num)
    {
        if(!u) return;
        dfs(u->right, k, num);
        k--;
        if(k == 0){
            num = u->val;
            return;
        }
        dfs(u->left, k, num);
    }

    int kthLargest(TreeNode* root, int k) {
        int num = 0;
        dfs(root, k, num);
        return num;
    }
};
