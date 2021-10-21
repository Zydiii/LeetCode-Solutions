class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long long> dp (t.length() + 1);
        if(s.length() > 0)
            dp[0] = 1;
        
        for(int i = 0; i < s.length(); i++)
        {
            for(int j = min(i, t.length() - 1); j >= 0; j--)
            {
                if(s[i] == t[j])
                    dp[j + 1] = dp[j] > INT_MAX ? 0 : dp[j + 1] + dp[j];
            }
        }

        return dp[t.length()];
    }

    int min(int i, int j)
    {
        return i > j ? j : i;
    }
};