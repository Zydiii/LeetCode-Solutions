/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int tmp = nums[0];

        int count = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != tmp)
            {
                count++;
                tmp = nums[i];
            }
            if(count == 3)
                return tmp;
        }

        return nums[0];
    }

    
};
// @lc code=end

