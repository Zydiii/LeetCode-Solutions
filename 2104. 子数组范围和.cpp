class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        for(int i = 0; i <nums.size(); i++)
        {
            int min = INT_MAX, max = INT_MIN;
            for(int j = i; j < nums.size(); j++)
            {
                min = min < nums[j] ? min : nums[j];
                max = max > nums[j] ? max : nums[j];
                result += max - min;
            }
        }
        return result;
    }
};