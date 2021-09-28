/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }

    bool helper(TreeNode* root, int targetSum, int sum)
    {
        if(root == nullptr)
            return false;
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr)
        {
            return targetSum == sum;
        }
        return helper(root->left, targetSum, sum) || helper(root->right, targetSum, sum);
    }
};
// @lc code=end

