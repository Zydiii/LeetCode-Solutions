class Solution {
public:
    int minCut(string s) {
        int size = s.length();
        vector<vector<bool>> isPar(size, vector<bool>(size));
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(s[i] == s[j] && (j == i - 1 || j == i || isPar[j + 1][i - 1]))
                    isPar[j][i] = true;
            }
        }

        vector<int> dp(size);
        for(int i = 0; i < size; i++)
        {
            if(isPar[0][i])
                dp[i] = 0;
            else
            {
                dp[i] = i;
                for(int j = 1; j <= i; j++)
                {
                    if(isPar[j][i])
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[size - 1];
    }
};