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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> cur;
        queue<TreeNode*> next;
        if(root != nullptr)
            cur.push(root);
        while(!cur.empty())
        {
            TreeNode* node = cur.front();
            cur.pop();
            if(node->left)
                next.push(node->left);
            if(node->right)
                next.push(node->right);
            if(cur.empty())
            {
                cur = next;
                next = queue<TreeNode*>();
                result.push_back(node->val);
            }
        }
        return result;
    }
};