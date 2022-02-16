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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> cur;
        queue<TreeNode*> next;
        if(root != nullptr)
            cur.push(root);
        
        int max = INT_MIN;
        while(!cur.empty())
        {
            TreeNode* node = cur.front();
            cur.pop();
            max = max > node->val ? max : node->val;
            if(node->left != nullptr)
                next.push(node->left);
            if(node->right != nullptr)
                next.push(node->right);
            if(cur.empty())
            {
                result.push_back(max);
                max = INT_MIN;
                cur = next;
                next = queue<TreeNode*>();
            }
        }

        return result;
    }
};