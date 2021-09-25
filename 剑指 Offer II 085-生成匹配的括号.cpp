class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string subset;
        helper(result, subset, n, n);
        return result;
    }

    void helper(vector<string> &result, string subset, int left, int right)
    {
        if(left == 0 && right == 0)
        {
            result.push_back(subset);
        }

        if(left > 0)
        {
            helper(result, subset + "(", left - 1, right);
        }

        if(right > left)
        {
            helper(result, subset + ")", left, right - 1);
        }
    }
};