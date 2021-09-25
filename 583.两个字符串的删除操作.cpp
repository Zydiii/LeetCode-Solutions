/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int maxSubstr = getMaxSubstr(word1, word2);
        return word1.length() + word2.length() - 2 * maxSubstr;
    }

    int getMaxSubstr(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> result(m + 1, vector<int>(n + 1));

        for(int i = 1; i <= m; i ++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
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

