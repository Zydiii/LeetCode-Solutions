/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        vector<string> words= split(text, ' ');
        for(int i = 2; i < words.size(); i++)
        {
            if(words[i - 1] == second && words[i - 2] == first)
                result.push_back(words[i]);
        }
        return result;
    }

    vector<string> split(string s, char c)
    {
        vector<string> results;
        string ss;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == c)
            {
                results.push_back(ss);
                ss = "";
            }
            else
            {
                ss += s[i];
            }
        }
        if(ss != "")
            results.push_back(ss);
        return results;
    }
};
// @lc code=end

