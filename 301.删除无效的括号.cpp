/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;

        int lremove = 0, rremove = 0;
        for(char c : s)
        {
            if(c == '(')
                lremove++;
            else if(c == ')')
            {
                if(lremove == 0)
                    rremove++;
                else
                    lremove--;
            }
        }

        helper(result, s, 0, 0, 0, lremove, rremove);

        return result;
    }

    bool isValid(string s)
    {
        int cnt = 0;
        for(char c : s)
        {
            if(c == '(')
                cnt++;
            else if(c == ')')
            {
                cnt--;
                if(cnt < 0)
                    return false;
            }
        }

        return cnt == 0;
    }

    void helper(vector<string> &result, string s, int start, int lcount, int rcount, int lremove, int rremove)
    {
        if(lremove == 0 && rremove == 0)
        {
            if(isValid(s))
                result.push_back(s);
            return;
        }

        for(int i = start; i < s.size(); i++)
        {
            
            if(i != start && s[i] == s[i - 1])
            {
                if(s[i] == '(')
                    lcount++;
                else if(s[i] == ')')
                    rcount++;
                continue;
            }
            if(lremove + rremove > s.size() - i)
                return;
            if(lremove > 0 && s[i] == '(')
                helper(result, s.substr(0, i) + s.substr(i + 1), i, lcount, rcount, lremove - 1, rremove);
            if(rremove > 0 && s[i] == ')')
                helper(result, s.substr(0, i) + s.substr(i + 1), i, lcount, rcount, lremove, rremove - 1);
                
            if(s[i] == '(')
                lcount++;
            else if(s[i] == ')')
                rcount++;
            if(rcount > lcount)
                break;
        }
    }
};
// @lc code=end

