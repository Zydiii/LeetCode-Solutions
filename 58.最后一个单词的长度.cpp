/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int flag = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(flag)
            {
                if(s[i] != ' ')
                {
                    count++;
                }
                else
                {
                    flag = 0;
                }
            }
            else
            { 
                if(s[i] != ' ')
                {
                    count = 1;
                    flag = 1;
                }
            }
        }

        return count;
    }
};
// @lc code=end

