/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int flag = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                flag = 0;
            }
            else
            {
                if(flag == 0)
                    count++;
                flag = 1;
            }
        }

        return count;
    }
};
// @lc code=end

