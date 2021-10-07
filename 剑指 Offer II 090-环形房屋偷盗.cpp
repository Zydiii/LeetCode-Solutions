class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() - 1));
    }

    int helper(vector<int>& nums, int start, int end)
    {
        vector<int> dp(2);
        dp[0] = nums[start];
        if(start < end)
            dp[1] = max(nums[start], nums[start + 1]);
        
        for(int i = start + 2; i <= end; i++)
        {
            int j = i - start;
            dp[j % 2] = max(dp[(j - 1) % 2], dp[(j - 2) % 2] + nums[i]);
        }

        return dp[(end - start) % 2];
    }
};