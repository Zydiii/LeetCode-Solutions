class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        healper(nums, result, 0);
        return result;
    }

    void healper(vector<int>& nums, vector<vector<int>>& result, int i)
    {
        if(i == nums.size() - 1)
        {
            result.push_back(nums);
        }
        else
        {
            for(int j = i; j < nums.size(); j++)
            {
                swap(nums, i, j);
                healper(nums, result, i + 1);
                swap(nums, i, j);
            }
        }

    }

    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};