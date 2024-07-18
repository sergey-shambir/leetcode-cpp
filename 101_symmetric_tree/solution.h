#pragma once

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
    bool isSymmetric(TreeNode* root)
    {
        if (!root)
        {
            return true;
        }
        return areSymmetric(root->left, root->right);
    }

private:
    bool areSymmetric(TreeNode* left, TreeNode* right) const
    {
        if (left != nullptr && right != nullptr)
        {
            return (left->val == right->val) && areSymmetric(left->left, right->right) && areSymmetric(left->right, right->left);
        }
        return (left == nullptr && right == nullptr);
    }
};
