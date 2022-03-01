/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* tmp = root;
        TreeNode* result = NULL;
        while(tmp != NULL)
        {
            if(tmp->val > p->val)
            {
                result = tmp;
                tmp = tmp->left;
            }
            else
            {
                tmp = tmp->right;
            }
        }
        return result;

    }
};