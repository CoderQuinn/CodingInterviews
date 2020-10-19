//
//  34 pathSum.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/9.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
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
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return res;
    }
    
    void dfs(TreeNode* root, int sum)
    {
        if (!root) return;
        
        path.push_back(root->val);
        sum -= root->val;
        
        if (!root->left && !root->right && sum == 0) {
            res.push_back(path);
        }
        
        dfs(root->left, sum);
        dfs(root->right, sum);
        
        // 恢复现场
        path.pop_back();
        sum += root->val;
    }
};
