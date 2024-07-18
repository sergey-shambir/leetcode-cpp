#pragma once

#include <utility>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    explicit TreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : val(val)
        , left(left)
        , right(right)
    {
    }
};

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root)
        {
            std::swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
