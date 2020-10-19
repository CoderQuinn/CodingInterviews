//
//  32 - I levelOrder.cpp
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
    vector<int> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        
        while (!nodes.empty()) {
            auto size = nodes.size();

            for (int i = 0; i < size; ++i) {
                TreeNode * curr = nodes.front();
                res.push_back(curr->val);
                nodes.pop();
                
                if (curr->left) {
                    nodes.push(curr->left);
                }
                if (curr->right) {
                    nodes.push(curr->right);
                }
            }
        }
        
        return res;
    }
};
