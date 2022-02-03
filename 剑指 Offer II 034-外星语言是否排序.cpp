class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> maps(26);
        for(int i = 0; i < order.size(); i++)
        {
            char c = order[i];
            maps[c - 'a'] = i;
        }
        for(int i = 0; i < words.size() - 1; i++)
        {
            string word0 = words[i];
            string word1 = words[i + 1];
            int j = 0;
            for(; j < word0.size() && j < word1.size(); j++)
            {
                if(maps[word0[j] - 'a'] < maps[word1[j] - 'a'])
                {
                    j = word0.size();
                    break;
                }
                if(maps[word0[j] - 'a'] > maps[word1[j] - 'a'])
                    return false;
            }
            if(j != word0.size())
                return false;
        }
        return true;
    }
};