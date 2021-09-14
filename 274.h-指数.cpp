/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int length = citations.size(), h;
        for(int i = 0; i < length; i++)
        {
            h = length - i;
            if(citations[i] > h || citations[i] == h)
              return h;
        }
        return 0;
    }
};
// @lc code=end

