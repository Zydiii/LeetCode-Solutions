/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1)
            return 0;
        
        if(n % 2)
            return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        
        return 1 + integerReplacement(n / 2);
    }
};
// @lc code=end

