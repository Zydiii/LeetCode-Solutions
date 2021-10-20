class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;
        if(s1.length() < s2.length())
            return isInterleave(s2, s1, s3);

        vector<bool> dp (s2.length() + 1);
        dp[0] = true;

        for(int j = 0; j < s2.length(); j++)
        {
            dp[j + 1] = s2[j] == s3[j] && dp[j]; 
        }

        for(int i = 0; i < s1.length(); i++)
        {
            dp[0] = dp[0] && s1[i] == s3[i];
            for(int j = 0; j < s2.length(); j++)
            {
                char ch1 = s1[i];
                char ch2 = s2[j];
                char ch3 = s3[i + j + 1];
                dp[j + 1] = (ch1 == ch3 && dp[j + 1]) || (ch2 == ch3 && dp[j]);
            }
        }

        return dp[s2.length()];

    }
};