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
    int pathSum(TreeNode* root, int targetSum) {
        map<int, int> path;
        path[0] = 1;
        return dfs(root, path, targetSum, 0);
    }

    int dfs(TreeNode* node, map<int, int> &path, int targetSum, int sum)
    {
        if(node == nullptr)
            return 0;

        sum += node->val;
        int count = path[sum - targetSum];

        path[sum]++;
        
        count += dfs(node->left, path, targetSum, sum);
        count += dfs(node->right, path, targetSum, sum);

        path[sum]--;

        return count;
    }
};