/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int sizeA = m, sizeB = n;
        for(int i = 0; i < ops.size(); i++)
        {
            int a = ops[i][0];
            int b = ops[i][1];
            sizeA = min(sizeA, a);
            sizeB = min(sizeB, b);
        }
        return sizeA * sizeB;
    }
};
// @lc code=end

