class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        
        if(sum % 2 == 1)
            return false;
        
        return subsetSum(nums, sum / 2);
    }

    bool subsetSum(vector<int> &nums, int target)
    {
        vector<bool> dp (target + 1);
        dp[0] = true;

        for(int i = 1; i <= nums.size(); i++)
        {
            for(int j = target; j > 0; j--)
            {
                if(!dp[j] && j >= nums[i - 1])
                    dp[j] = dp[j - nums[i - 1]];
            }
        }

        return dp[target];
    }
};