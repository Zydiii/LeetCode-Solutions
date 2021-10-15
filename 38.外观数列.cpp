/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string pre = "1";
        for(int i = 1; i < n; i++)
        {
            pre = detailLastNum(pre);
        }
        return pre;
    }


    string detailLastNum(string s)
    {
        char last, now;
        int lastNum = 0;
        string result;

        for(int i = 0; i < s.length(); i++)
        {
            now = s[i];
            if(i != 0)
            {
                // cout << now << endl;
                if(last == now)
                {
                    lastNum++;
                }
                else
                {
                    result += to_string(lastNum);
                    result += last;
                    lastNum = 1;
                }
            }
            else
                lastNum = 1;
            last = now; 
        }
        if(lastNum != 0)
        {
            result += to_string(lastNum);
            result += last;
        }

        return result;
    }
};
// @lc code=end

