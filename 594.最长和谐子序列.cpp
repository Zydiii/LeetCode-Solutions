/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> masks;
        for(int num : nums)
        {
            if(masks.find(num) != masks.end())
            {
                masks[num]++;
            }
            else
            {
                masks[num] = 1;
            }
        }

        map<int, int>::iterator it = masks.begin();
        int result = 0;
        while(it != masks.end())
        {
            int x1 = it->first + 1;
            int x2 = it->first - 1;
            if(masks.find(x1) != masks.end())
                result = max(result, it->second + masks[x1]);
            if(masks.find(x2) != masks.end())
                result = max(result, it->second + masks[x2]);
            it++;
        }

        return result;
    }
};
// @lc code=end

