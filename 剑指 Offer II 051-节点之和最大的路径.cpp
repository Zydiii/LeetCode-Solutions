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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    int dfs(TreeNode* node, int &maxSum)
    {
        if(node == nullptr)
            return 0;
        int maxLeft = INT_MIN;
        int maxRight = INT_MIN;
        int left = max(0, dfs(node->left, maxLeft));
        int right = max(0, dfs(node->right, maxRight));
        maxSum = max(maxRight, maxLeft);
        maxSum = max(maxSum, node->val + left + right);

        return node->val + max(left, right);
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};