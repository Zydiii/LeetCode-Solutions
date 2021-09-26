/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0)
        {
            unsigned int addOne = (unsigned int) (a & b) << 1;
            a =  a ^ b;
            b = addOne;
        }
        return a;
    }
};
// @lc code=end

