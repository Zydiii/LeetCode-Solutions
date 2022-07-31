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
    int maxLevelSum(TreeNode* root) {
        int level = 0, maxLevel = 0, sum = 0, maxSum = INT_MIN, size = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            size = q.size();
            sum = 0;
            level++;
            for(int s{0}; s < size; s++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(maxSum < sum){
                maxSum = sum;
                maxLevel = level;
            }
        }
        return maxLevel;
    }
};