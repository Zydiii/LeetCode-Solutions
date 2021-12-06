/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */

// @lc code=start
class Solution {
public:
    string truncateSentence(string s, int k) {
        string result;
        string word;
        for(char c : s)
        {
            if(c == ' ')
            {           
                k--;
                result += word;

                // cout << word << endl;
                // cout << k << endl;
                // cout << result << endl;

                if(k == 0)
                    break;

                result += ' ';
                word = "";
            }
            else
                word += c;
        }

        if(k != 0)
            result += word;

        return result;
    }
};
// @lc code=end

