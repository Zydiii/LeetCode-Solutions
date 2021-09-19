/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        vector<int> result(n + 1);
        
        for(int i = 2; i <= n; i++)
        {
            result[i] = INT_MAX;

            for(int j = 1; j * j <= i; j++)
            {
                if(i % j == 0)
                {
                    result[i] = min(result[i], result[j] + i / j);
                    result[i] = min(result[i], result[i / j] + j);
                }
            }
        }

        return result[n];
    }


};
// @lc code=end

