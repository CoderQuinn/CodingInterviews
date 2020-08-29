//
//  07 buildTree.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        return build_tree_helper(preorder, 0, int(preorder.size() - 1), inorder, 0, int(inorder.size() - 1));
    }
    
    TreeNode* build_tree_helper(vector<int>& preorder, int pre_l, int pre_r, vector<int>& inorder, int in_l, int in_r) {
        if (pre_l > pre_r) {
            return nullptr;
        }
        
        if (pre_l == pre_r) {
            return new TreeNode(preorder[pre_l]);
        }
        
        int root_val = preorder[pre_l];

        int i = in_l;
        for (; i <= in_r; i++) {
            if (inorder[i] == root_val) {
                break;
            }
        }
        int size = i - in_l;
        
        TreeNode *root = new TreeNode(root_val);
        
        root->left = build_tree_helper(preorder, pre_l + 1, pre_l + size, inorder, in_l, in_l + size - 1);
        root->right= build_tree_helper(preorder, pre_l + size + 1, pre_r, inorder, in_l + size + 1, in_r);
        
        return root;
    }
};
