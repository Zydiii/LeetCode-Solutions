class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b){
            if(a.size() != b.size())
                return a.size() < b.size();
            else
                return a > b;
        });

        unordered_set<string> set;
        string result = "";
        set.emplace(result);

        for(auto &word : words)
        {
            if(set.count(word.substr(0, word.size() - 1)) > 0)
            {
                set.emplace(word);
                result = word;
            }
        }

        return result;
    }
};
