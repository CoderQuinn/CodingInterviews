//
//  68 - II lowestCommonAncestor.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <cstdio>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode *, TreeNode *> parent_map;
    void bfs(TreeNode *root) {
        if (!root) return;
        
        if (root->left) {
            parent_map[root->left] = root;
            bfs(root->left);
        }
        
        if (root->right) {
            parent_map[root->right] = root;
            bfs(root->right);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        
        parent_map[root] = nullptr;
        bfs(root);
        
        TreeNode *node_p = p;
        TreeNode *node_q = q;
        while (node_p || node_q) {
            if (!node_p) {
                node_p = q;
            }
            
            if (!node_q) {
                node_q = p;
            }
            
            if (node_p == node_q) {
                return node_p;
            }
            
            node_p = parent_map[node_p];
            node_q = parent_map[node_q];
        }
        return nullptr;
    }
};

class Solution1 {
public:
    TreeNode *res = NULL;
    int bfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0x00;
        int state = bfs(root->left, p, q);

        if (root == p) {
            state |= 0x01;
        } else if(root == q) {
            state |= 0x10;
        }
        
        state  |= bfs(root->right, p, q);
        
        if (state == 0x11 && !res) {
            res = root;
        }
        
        return state;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bfs(root, p, q);
        return res;
    }
};
