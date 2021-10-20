/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minValue = *min_element(nums.begin(), nums.end());
        int result = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            result += nums[i] - minValue;
        }
        return result;
    }
};
// @lc code=end

