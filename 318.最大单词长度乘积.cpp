/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size());
        for(int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            for(int j = 0; j < word.size(); j++)
            {
                masks[i] |=  1 << (word[j] - 'a');
            }
        }

        int result = 0;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                if((masks[i] & masks[j]) == 0)
                {
                    result = result > words[i].size() * words[j].size() ? result : words[i].size() * words[j].size();
                }
            }
        }

        return result;
    }
};
// @lc code=end

