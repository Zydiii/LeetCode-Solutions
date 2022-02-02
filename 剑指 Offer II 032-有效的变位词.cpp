class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s == t || s.length() != t.length())
            return false;

        vector<int> map(26);
        for(char c : s)
        {
            map[c - 'a']++;
        }
        for(char c : t)
        {
            if(map[c - 'a'] == 0)
                return false;
            map[c - 'a']--; 
        }
        return true;
    }
};