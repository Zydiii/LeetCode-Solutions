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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        int val = 0;
        while(cur != nullptr || !s.empty())
        {
            while(cur != nullptr)
            {
                s.push(cur);
                cur = cur->right;
            }
            cur = s.top();
            s.pop();
            int v = cur->val;
            cur->val += val;
            val += v;
            cur = cur->left;
        }
        return root;
    }
};