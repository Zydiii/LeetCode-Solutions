/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string string0 = "qwertyuiop";
        string string1 = "asdfghjkl";
        string string2 = "zxcvbnm";
        map<char, int> helper;
        for (char c : string0)
        {
            helper[c] = 0;
        }
        for (char c : string1)
        {
            helper[c] = 1;
        }
        for (char c : string2)
        {
            helper[c] = 2;
        }

        vector<string> result;
        for(string s : words)
        {
            int flag = helper[tolower(s[0])];
            int right = 1;
            for(char c : s)
            {
                c = tolower(c);
                if(helper[c] != flag)
                {
                    right = 0;
                    break;
                }
            }
            if(right)
                result.push_back(s);
        }

        return result;
    }
};
// @lc code=end

