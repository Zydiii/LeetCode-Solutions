/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "#";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + "," + right; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        vector<string> s = split(data);
        return dfs(s, index);
    }

    vector<string> split(string data)
    {
        return stringSplit(data, ',');
    }

    vector<string> stringSplit(string str, char delim) {
        int previous = 0;
        int current = str.find(delim);
        vector<string> elems;
        while (current != std::string::npos) {
            if (current > previous) {
                elems.push_back(str.substr(previous, current - previous));
            }
            previous = current + 1;
            current = str.find(delim, previous);
        }
        if (previous != str.size()) {
            elems.push_back(str.substr(previous));
        }
        return elems;
    }

    TreeNode* dfs(vector<string> &data, int &index)
    {
        string s = data[index];
        index++;
        if(s == "#")
            return NULL;
        TreeNode* node = new TreeNode(stoi(s));
        node->left = dfs(data, index);
        node->right = dfs(data, index);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));