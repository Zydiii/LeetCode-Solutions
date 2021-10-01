/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> cityA;

        for(int i = 0; i < paths.size(); i++)
        {
            cityA.insert(paths[i][0]);
        }

        for(int i = 0; i < paths.size(); i++)
        {
            if(cityA.find(paths[i][1]) == cityA.end())
                return paths[i][1];
        }

        return "";
    }
};
// @lc code=end

