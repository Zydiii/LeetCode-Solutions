/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

// @lc code=start
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        int n = num.length();
        vector<string> ans;
        string expr;
        helper(expr, 0, 0, 0, n, ans, num, target);
        return ans;
    }

    void helper(string &expr, int i, long res, long mul, int n, vector<string>& ans, string num, int target)
    {
        if(i == n)
        {
            if(res == target)
                ans.push_back(expr);
        }
        
        int signIndex = expr.size();
        if(i > 0)
            expr.push_back(0);
        long val = 0;

        for(int j = i; j < n && (j == i || num[i] != '0'); ++j)
        {
            val = val * 10 + num[j] - '0';
            expr.push_back(num[j]);
            if(i == 0)
            {
                helper(expr, j + 1, val, val, n, ans, num, target);
            }
            else
            {
                expr[signIndex] = '+';
                helper(expr, j + 1, res + val, val, n, ans, num, target);
                expr[signIndex] = '-';
                helper(expr, j + 1, res - val, -val, n, ans, num, target);
                expr[signIndex] = '*';
                helper(expr, j + 1, res - mul + mul * val, mul * val, n, ans, num, target);
            }
        }
        expr.resize(signIndex);
    }
};

// @lc code=end

