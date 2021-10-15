class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        if(len1 < len2)
        {
            string tmp = text1;
            text1 = text2;
            text2 = tmp;
            len1 = text1.length();
            len2 = text2.length();
        }

        vector<int> dp(len2 + 1);
        int pre, cur;
        for(int i = 0; i < len1; i++)
        {
            pre = dp[0];
            for(int j = 0; j < len2; j++)
            {
                if(text1[i] == text2[j])
                {
                    cur = pre + 1;
                }
                else
                {
                    cur = max(dp[j], dp[j + 1]);
                }
                pre = dp[j + 1];
                dp[j + 1] = cur;
            }
        }

        return dp[len2];
    }
};