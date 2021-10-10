/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int k = 1;
        while(n >= k)
        {
            n -= k;
            k++;
        }
        return --k;
    }
};
// @lc code=end

