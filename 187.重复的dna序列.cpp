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

        cout << s.length() - 10 << endl;

        for(int i = 0; i < s.length() - 10; i++)
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

