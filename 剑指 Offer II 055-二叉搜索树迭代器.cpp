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
class BSTIterator {
    TreeNode* cur;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        while(cur != nullptr)
        {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        int val = cur->val;
        cur = cur->right;
        return val;
    }
    
    bool hasNext() {
        return cur != nullptr || !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */