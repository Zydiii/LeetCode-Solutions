/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for(int n : nums)
        {
            if(mp.find(n) != mp.end())
                mp[n]++;
            else
                mp[n] = 1;
        }

        map<int, int>::iterator it = mp.begin();
        vector<int> result;
        int size = nums.size() / 3;
        for(;it!=mp.end(); it++)
        {
            if(it->second > size)
            {
                result.push_back(it->first);
            }
        }

        return result;
    }
};
// @lc code=end

