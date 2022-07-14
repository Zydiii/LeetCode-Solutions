struct Trie {
    unordered_map<string, Trie*> node;
    int size;
};

class WordFilter {
    Trie *trie;

public:
    WordFilter(vector<string>& words) {
        trie = new Trie();
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            Trie *cur = trie;
            int m = word.size();
            for(int j = 0; j < m; j++) {
                Trie *tmp = cur;
                for(int k = j; k < m; k++) {
                    string key({word[k], '#'});
                    if(!tmp->node.count(key)) {
                        tmp->node[key] = new Trie();
                    }
                    tmp = tmp->node[key];
                    tmp->size = i;
                }
                tmp = cur;
                for (int k = j; k < m; k++) {
                    string key({'#', word[m - k - 1]});
                    if (!tmp->node.count(key)) {
                        tmp->node[key] = new Trie();
                    }
                    tmp = tmp->node[key];
                    tmp->size = i;
                }
                string key({word[j], word[m - j - 1]});
                if (!cur->node.count(key)) {
                    cur->node[key] = new Trie();
                }
                cur = cur->node[key];
                cur->size = i;
            }
        }
    }
    
    int f(string pref, string suff) {
        Trie *cur = trie;
        int m = max(pref.size(), suff.size());
        for (int i = 0; i < m; i++) {
            char c1 = i < pref.size() ? pref[i] : '#';
            char c2 = i < suff.size() ? suff[suff.size() - 1 - i] : '#';
            string key({c1, c2});
            if (!cur->node.count(key)) {
                return -1;
            }
            cur = cur->node[key];
        }
        return cur->size;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
