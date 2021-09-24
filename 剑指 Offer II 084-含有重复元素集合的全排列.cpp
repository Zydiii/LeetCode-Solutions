class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        helper(result, nums, 0);
        return result;
    }

    void helper(vector<vector<int>>& result, vector<int>& nums, int index)
    {
        if(index == nums.size() - 1)
        {
            result.push_back(nums);
        }
        else
        {
            set<int> swappedSet;
            for(int j = index; j < nums.size(); j++)
            {
                if(swappedSet.find(nums[j]) != swappedSet.end())
                    continue;
                swappedSet.insert(nums[j]);
                swap(nums, index, j);
                helper(result, nums, index + 1);
                swap(nums, index, j);
            }
        }
    }

    void swap( vector<int>& nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};