class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> dp (row);

        for(int i = 0; i < row; i++)
        {
            for(int j = i; j >= 0; j--)
            {
                if(j == 0)
                    dp[j] += triangle[i][j];
                else if(j == i)
                    dp[j] = dp[j - 1] + triangle[i][j];
                else
                    dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }
        }

        int result = dp[0];
        for(int i = 1; i < row; i++)
        {
            result = min(result, dp[i]);
        }

        return result;
    }
};