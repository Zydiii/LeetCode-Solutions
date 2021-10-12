/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN)
        {
            if(divisor == 1)
                return INT_MIN;
            if(divisor == -1)
                return INT_MAX;
        }
        if(divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        if(divisor == 0)
            return 0;

        bool neg = false;
        if(dividend > 0)
        {
            dividend = -dividend;
            neg = !neg;
        }
        if(divisor > 0)
        {
            divisor = -divisor;
            neg = !neg;
        }

        int left = 1, right = INT_MAX, result = 0;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            bool check = quickMulti(divisor, mid, dividend);
            if(check)
            {
                result = mid;
                if(mid == INT_MAX)
                    break;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }

        return neg ? -result : result;
    }

    bool quickMulti(int y, int z, int x)
    {
        int result = 0, add = y;

        while(z)
        {
            if(z & 1)
            {
                if(result < x - add)
                {
                    return false;
                }
                result += add;
            }
            if(z != 1)
            {
                if(add < x - add)
                {
                    return false;
                }
                add += add;
            }
            z >>= 1;
        }
        return true;
    }
};
// @lc code=end

