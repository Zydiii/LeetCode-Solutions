class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> result;
        getSubset(nums, subset, result, 0);
        return result;
    }

    void getSubset(vector<int>& nums, vector<int> subset, vector<vector<int>>& result, int index)
    {
        if(index == nums.size())
            result.push_back(subset);
        else
        {
            getSubset(nums, subset, result, index + 1);
            subset.push_back(nums[index]);
            getSubset(nums, subset, result, index + 1);
        }
    }
};