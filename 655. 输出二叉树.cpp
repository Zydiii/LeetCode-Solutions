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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = -1;
        queue<TreeNode*> q;
        q.push(root);
        int size = q.size();
        while(!q.empty()){
            for(int s{0}; s < size; ++s){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            size = q.size();
            height++;
        }
        
        int m = height + 1, n = pow(2, m) - 1;
        vector<vector<string>> vec(m, vector<string>(n, ""));
        
        q.push(root);
        size = q.size();
        map<TreeNode*, pair<int, int>> mm;
        mm[root] = make_pair<int, int>(0, (n - 1) / 2);
        while(!q.empty()){
            for(int s{0}; s < size; ++s){
                TreeNode* node = q.front();
                q.pop();
                int r = mm[node].first;
                int c = mm[node].second;
                vec[r][c] = to_string(node->val);
                //std::cout << "value " << node->val << std::endl;
                if(node->left){
                    mm[node->left] = make_pair<int, int>(r + 1, c - pow(2, height - r - 1));
                    q.push(node->left);
                }
                if(node->right){
                    mm[node->right] = make_pair<int, int>(r + 1, c + pow(2, height - r - 1));
                    q.push(node->right);
                }
            }
            size = q.size();
        }

        return vec;
    }
};