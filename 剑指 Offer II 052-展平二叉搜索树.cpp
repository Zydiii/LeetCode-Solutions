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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        while(cur != nullptr || !stack.empty())
        {
            while(cur != nullptr)
            {
                stack.push(cur);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();

            if(prev == nullptr)
                first = cur;
            else
                prev->right = cur;
            
            prev = cur;
            cur->left = nullptr;
            cur = cur->right;
        }
        return first;
    }
};