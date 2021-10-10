class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp (2, vector<int>(2));
        if(s[0] == '0')
        {
            dp[0][0] = 0;
            dp[0][1] = 1;
        }
        else
        {
            dp[0][0] = 1;
            dp[0][1] = 0;
        }

        for(int i = 1; i < s.length(); i++)
        {
            int pre0 = dp[(i - 1) % 2][0];
            int pre1 = dp[(i - 1) % 2][1];
            
            if(s[i] == '0')
            {
                dp[i % 2][0] = pre0;
                dp[i % 2][1] = min(pre0, pre1) + 1;
            }
            else
            {
                dp[i % 2][0] = pre0 + 1;
                dp[i % 2][1] = min(pre0, pre1);
            }
        }

        return min(dp[(s.length() - 1) % 2][0], dp[(s.length() - 1) % 2][1]);
    }
};