/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result (nums.size());

        for(int i = 0; i < result.size(); i++)
        {
            result[i] = 1;

            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    result[i] = max(result[i], result[j] + 1);
            }
        }

        sort(result.begin(), result.end());

        return result[result.size() - 1];
    }

    
};
// @lc code=end

