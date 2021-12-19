/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1 && trust.size() == 0)
            return 1;

        unordered_map<int, int> trustNum;
        unordered_map<int, int> betrustNum;

        for(int i = 0; i < trust.size(); i++)
        {
            trustNum[trust[i][0]]++;
            betrustNum[trust[i][1]]++;
        }

        unordered_map<int, int>::iterator iter = betrustNum.begin();
        while(iter != betrustNum.end())
        {
            if(betrustNum[iter->first] == n - 1)
            {
                if(trustNum.find(iter->first) == trustNum.end())
                {
                    return iter->first;
                }
            }
            iter++;
        }
        
        return -1;
    }
};
// @lc code=end

