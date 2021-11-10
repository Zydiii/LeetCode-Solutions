class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num : nums)
        {
            sum += num;
        }
        if(sum < target || (sum + target) % 2 == 1)
            return 0;
        return helper(nums, (sum + target) / 2);
    }

    int helper(vector<int>& nums, int target)
    {
        vector<int> dp(target + 1);
        dp[0] = 1;

        for(int num : nums)
        {
            for(int j = target; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }
        return dp[target];
    }
};