/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n >= 0)
            return helper(x, n);
        else
            return 1 / helper(x, n);
    }

    double helper(double x, int n)
    {
        if(n == 0)
            return 1;
        
        double sub = helper(x, n / 2);
        if(n % 2)
            return sub * sub * x;
        else
            return sub * sub;
    }
};
// @lc code=end

