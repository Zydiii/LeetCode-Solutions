/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size(), l = 0, r = length - 1, mid, h;
        while(l < r)
        {
            mid = (l + r) / 2;
            h = length - mid;
            if(citations[mid] < h)
              l = mid + 1;
            if(citations[mid] >= h)
              r = mid;   
        }
        return citations[r] >= length - r ? length - r : 0;
    }
};
// @lc code=end

