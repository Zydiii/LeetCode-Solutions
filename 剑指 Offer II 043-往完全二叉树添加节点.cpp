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
class CBTInserter {
    TreeNode* root;
    queue<TreeNode*> nodes;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        nodes.push(root);
        while(nodes.front()->left != NULL && nodes.front()->right != NULL)
        {
            nodes.push(nodes.front()->left);
            nodes.push(nodes.front()->right);
            nodes.pop();
        }
    }
    
    int insert(int v) {
        int result = nodes.front()->val;
        if(nodes.front()->left == NULL)
        {
            nodes.front()->left = new TreeNode(v);
        }
        else
        {
            nodes.front()->right = new TreeNode(v);
            nodes.push(nodes.front()->left);
            nodes.push(nodes.front()->right);
            nodes.pop();
        }
        return result;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */