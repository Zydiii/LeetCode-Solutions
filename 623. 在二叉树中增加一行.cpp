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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        else{
            queue<TreeNode*> q;
            int size;
            q.push(root);
            for(int d = 2; d < depth; d++){
                size = q.size();
                for(int s{0}; s < size; s++){
                    TreeNode* node = q.front();
                    q.pop();
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                }
            }
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                    TreeNode* newNode = new TreeNode(val);
                    newNode->left = node->left;
                    node->left = newNode;
                    newNode = new TreeNode(val);
                    newNode->right = node->right;
                    node->right = newNode;
            }
            return root;
        }
    }
};