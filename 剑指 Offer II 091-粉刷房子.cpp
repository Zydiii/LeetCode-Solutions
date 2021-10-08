class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> result (2, vector<int>(3));
        result[0][0] = costs[0][0];
        result[0][1] = costs[0][1];
        result[0][2] = costs[0][2];

        for(int i = 1; i < costs.size(); i++)
        {
            result[i % 2][0] = min(result[(i - 1) % 2][1], result[(i - 1) % 2][2]) + costs[i][0];
            result[i % 2][1] = min(result[(i - 1) % 2][0], result[(i - 1) % 2][2]) + costs[i][1];
            result[i % 2][2] = min(result[(i - 1) % 2][0], result[(i - 1) % 2][1]) + costs[i][2];
        }

        return minThree(result[(costs.size() - 1) % 2][0], result[(costs.size() - 1) % 2][1], result[(costs.size() - 1) % 2][2]);

    }

    int minThree(int a, int b, int c)
    {
        return min(a, min(b, c));
    }
};