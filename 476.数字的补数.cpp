/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int origNum = num;
        int maxBit = 0;

        while(num > 0)
        {
            num >>= 1;
            maxBit++;
        }

        int mask = maxBit == 31 ? 0x7fffffff : (1 << maxBit) - 1;

        return origNum ^ mask;
    }
};
// @lc code=end

