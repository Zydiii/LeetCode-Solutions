/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> result (m + 1, vector<int>(n + 1));
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(text1[i - 1] == text2[j - 1])
                {
                    result[i][j] = result[i - 1][j - 1] + 1;
                }
                else
                {
                    result[i][j] = max(result[i - 1][j], result[i][j - 1]);
                }
            }
        }
        return result[m][n];
    }
};
// @lc code=end

