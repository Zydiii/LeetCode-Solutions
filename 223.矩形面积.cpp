/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int s1 = (ax2 - ax1) * (ay2 - ay1), s2 = (bx2 - bx1) * (by2 - by1);
        if(s1 == 0 || s2 == 0)
            return s1 + s2;

        int x, y;
        if(ax1 < bx1)
        {
            x = ax2 <= bx1 ? 0 : min(bx2- bx1, max(0, ax2 - bx1));
            if(by1 < ay1)
            {
                y = ay1 >= by2 ? 0 : min(ay2 - ay1, max(0, by2 - ay1));
            }
            else
            {
                y = by1 >= ay2 ? 0 : min(by2 - by1, max(0, ay2 - by1));
            }
        }
        else
        {
            x = bx2 <= ax1 ? 0 : min(ax2 - ax1, max(0, bx2 - ax1));
            if(by1 < ay1)
            {
                y = ay1 >= by2 ? 0 : min(ay2 - ay1, max(0, by2 - ay1));
            }
            else
            {
                y = by1 >= ay2 ? 0 : min(by2 - by1, max(0, ay2 - by1));
            }
        }
        return s1 + s2 - x * y;
    }
};// @lc code=end

