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
    bool findTarget(TreeNode* root, int k) {
        set<int> remain_vals;
        return dfs(root, remain_vals, k);
    }

    bool dfs(TreeNode* node, set<int> &remain_vals, int k)
    {
        if(node == nullptr)
            return false;
        if(remain_vals.count(node->val))
            return true;
        remain_vals.insert(k - node->val);
        return dfs(node->left, remain_vals, k) || dfs(node->right, remain_vals, k);
    }

};