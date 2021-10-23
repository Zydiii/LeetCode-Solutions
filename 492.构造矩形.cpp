/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int n = sqrt(area);
        vector<int> result;

        for(int i = n; i > 1; i--)
        {
            if(area % i == 0)
            {
                result.push_back(area / i);
                result.push_back(i);
                return result;
            }
        }

        result.push_back(area);
        result.push_back(1);
        return result;
    }
};
// @lc code=end

