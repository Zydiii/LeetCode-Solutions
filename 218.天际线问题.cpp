/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> points;
        for(int i = 0; i < buildings.size(); i++)
        {
            points.insert(make_pair(buildings[i][0], -buildings[i][2]));
            points.insert(make_pair(buildings[i][1], buildings[i][2]));
        }

        vector<vector<int>> result;
        multiset<int> height({0});
        vector<int> lastCheckPoint = {0, 0};
        
        for(auto &point : points)
        {
            if(point.second < 0)
              height.insert(-point.second);
            else
              height.erase(height.find(point.second));
            
            int maxHeight = *height.rbegin();
            if(maxHeight != lastCheckPoint[1])
            {
                lastCheckPoint[0] = point.first;
                lastCheckPoint[1] = maxHeight;
                result.push_back(lastCheckPoint);
            }
        }

        return result;
    }
};
// @lc code=end

