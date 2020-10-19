//
//  32 - III levelOrder.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        int level = 0;
        while (!nodes.empty()) {
            auto size = nodes.size();
            vector<int> level_vec;
            for (int i = 0; i < size; ++i) {
                TreeNode * curr = nodes.front();
//                if(level % 2)
//                    level_vec.insert(level_vec.begin(), curr->val);
//                else
                    level_vec.push_back(curr->val);
                if (curr->left) {
                    nodes.push(curr->left);
                }
                if (curr->right) {
                    nodes.push(curr->right);
                }
                nodes.pop();
            }
            if(level % 2) reverse(level_vec.begin(), level_vec.end());
            res.push_back(level_vec);
            ++level;
        }
        
        return res;
    }
};
