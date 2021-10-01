class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp = {cost[0], cost[1]};
        for(int i = 2; i < cost.size(); i++)
        {
            dp[i % 2] = min(dp[0], dp[1]) + cost[i];
        }
        return min(dp[0], dp[1]);
    }
};