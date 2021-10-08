/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        map<string, int> subs;

        int n = s.length() - 10;

        for(int i = 0; i <= n; i++)
        {
            string tmp = s.substr(i, 10);
            if(++subs[tmp] == 2)
            {
                result.push_back(tmp);
            }
        }

        return result;
    }
};
// @lc code=end

