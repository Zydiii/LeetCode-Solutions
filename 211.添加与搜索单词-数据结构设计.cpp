/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
struct prefixTree{
    vector<prefixTree*> children;
    bool isEnd;

    prefixTree()
    {
        children.resize(26);
        isEnd = false;
    }

    void insert(string word)
    {
        prefixTree* node = this;
        for(char ch : word)
        {
            ch -= 'a';
            if(node->children[ch] == nullptr)
                node->children[ch] = new prefixTree();
            node = node->children[ch];
        }
        node->isEnd = true;
    }
};

class WordDictionary {
prefixTree* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new prefixTree();
    }
    
    void addWord(string word) {
        root->insert(word);
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int index, prefixTree* node){
        if(index == word.size())
            return node->isEnd;

        char ch = word[index];
        if(ch >= 'a' && ch <= 'z'){
            prefixTree* child = node->children[ch - 'a'];
            if(child != nullptr && dfs(word, index + 1, child))
                return true;
        }
        else if(ch == '.'){
            for(int i = 0; i < 26; i++){
                prefixTree* child = node->children[i];
                if(child != nullptr && dfs(word, index + 1, child))
                    return true;
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

