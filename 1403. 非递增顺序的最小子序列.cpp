class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> result;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        sum /= 2;
        for(size_t i{nums.size() - 1}; i >= 0; --i){
            result.push_back(nums[i]);
            sum -= nums[i];
            if(sum < 0)
                break;
        }
        return result;
    }
};