//
//  37 序列化二叉树.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/17.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <string>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void dfs_s(TreeNode *root, string &path)
    {
        if (!root) {
            path += "#,";
        } else {
            path += to_string(root->val) + ',';
            dfs_s(root->left, path);
            dfs_s(root->right, path);
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string path;
        dfs_s(root, path);
        return path;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
    }
    
    TreeNode *dfs_d(string data, int &u)
    {
        if (data[u] == '#') {
            u += 2;
            return nullptr;
        } else {
            int tmp = u;
            while (data[u] != ',') {
                u++;
            }
            string node = data.substr(tmp, u - tmp);
            u++;
            int val = stoi(node);
            TreeNode *root = new TreeNode(val);
            root->left = dfs_d(data, u);
            root->right = dfs_d(data, u);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
