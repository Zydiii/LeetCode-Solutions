/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int nextTime = timeSeries[0] + duration - 1, allTime = 0, beginTime = timeSeries[0];

        for(int i = 1; i < timeSeries.size(); i++)
        {
            int time = timeSeries[i];
            if(nextTime < time)
            {
                allTime += nextTime - beginTime + 1;
                beginTime = time;
            }
            nextTime = time + duration - 1;
        }

        allTime += nextTime - beginTime + 1;

        return allTime;
    }
};
// @lc code=end

