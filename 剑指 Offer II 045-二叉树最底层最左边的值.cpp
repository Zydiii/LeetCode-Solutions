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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> last;
        queue<TreeNode*> cur;
        queue<TreeNode*> next;
        cur.push(root);
        last = cur;
        while(!cur.empty())
        {
            TreeNode* node = cur.front();
            cur.pop();
            if(node->left != nullptr)
                next.push(node->left);
            if(node->right != nullptr)
                next.push(node->right);
            if(cur.empty())
            {
                cur = next;
                next = queue<TreeNode*>();
                if(!cur.empty())
                    last = cur;
            }
        }
        return last.front()->val;
    }
};