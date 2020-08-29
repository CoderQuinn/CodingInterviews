//
//  26 isSubStructure.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        
        return bfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    
    bool bfs(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        
        if (!A || A->val != B->val) return false;
        
        return bfs(A->left, B->left) && bfs(A->right, B->right);
    }
};

class Solution1 {
public:
    vector<TreeNode *> node_vec;
    
    void bfs(TreeNode *root, int target) {
        if (!root) return;
        
        if (root && root->val == target) {
            node_vec.push_back(root);
        }
        
        bfs(root->left, target);
        bfs(root->right, target);
    }
    
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        bfs(A, B->val);
        if (node_vec.empty()) return false;
        
        bool ret = false;
        for (auto node : node_vec) {
            if (node) {
                ret = (ret || is_sub_core(node, B));
            }
        }
        
        return ret;
    }
    
    bool is_sub_core(TreeNode* A, TreeNode* B) {
        if (!B) return true;

        if (B && !A) return false;
        
        if (A->val != B->val) return false;

        return is_sub_core(A->left, B->left) && is_sub_core(A->right, B->right);
    }
};

