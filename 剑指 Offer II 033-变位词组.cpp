class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> maps;
        for(string s : strs)
        {
            string ss = s;
            sort(s.begin(), s.end());
            maps[s].push_back(ss);
        }

        vector<vector<string>> result;
        map<string, vector<string>> :: iterator itr = maps.begin();
        while(itr != maps.end())
        {
            result.push_back(itr->second);
            itr++;
        }

        return result;
    }
};