/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
            
        string result;

        for(int i = 7; i >= 0; i--)
        {
            int digit = (num >> i * 4) & 0xf;
            if(result.length() || digit > 0)
            {
                result += digit >= 10 ? 'a' + digit - 10 : '0' + digit;
            }
        }

        return result;
    }
};
// @lc code=end

