/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int findTilt(TreeNode* root) {
        int result = 0;
        helper(root, result);
        return result;
    }

    int helper(TreeNode* root, int &result)
    {
        if(root == nullptr)
            return 0;
        
        int leftSum = helper(root->left, result);
        int rightSum = helper(root->right, result);
        result += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
};
// @lc code=end

