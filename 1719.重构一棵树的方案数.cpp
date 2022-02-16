/*
 * @lc app=leetcode.cn id=1719 lang=cpp
 *
 * [1719] 重构一棵树的方案数
 */

// @lc code=start
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adjs;
        for(vector<int> p : pairs)
        {
            adjs[p[0]].emplace(p[1]);
            adjs[p[1]].emplace(p[0]);
        }

        // 根据 degree = n - 1 找根节点
        int root = -1;
        for(auto &adj : adjs)
        {
            if(adj.second.size() == adjs.size() - 1)
            {
                root = adj.first;
                break;
            }
        }
        if(root == -1)
            return 0;
        
        int result = 1;
        // 判断其他节点的父子 degree
        for(auto &adj : adjs)
        {
            if(adj.first == root)
                continue;
            
            int curDegree = adj.second.size();
            int parent = -1;
            int parentDegree = INT_MAX;
            for(int neighbor : adj.second)
            {
                if(adjs[neighbor].size() >= curDegree && adjs[neighbor].size() < parentDegree)
                {
                    parent = neighbor;
                    parentDegree = adjs[neighbor].size();
                }
            }
            if(parent == -1)
                return 0;
            
            // 检查父子邻居节点
            for(int neighbor : adj.second)
            {
                if(neighbor == parent)
                    continue;
                if(adjs[parent].count(neighbor) == 0)
                    return 0;
            }

            if(curDegree == parentDegree)
                result = 2;
        }
        return result;
    }
};
// @lc code=end

