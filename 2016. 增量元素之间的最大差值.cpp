class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1, premin = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > premin)
            {
                result = result > nums[i] - premin ? result : nums[i] - premin;
            }
            else
            {
                premin = nums[i];
            }
        }
        return result;
    }
};