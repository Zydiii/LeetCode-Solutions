/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        s.erase(std::remove(s.begin(), s.end(), '-'), s.end());

        int size = s.length();
        int num = size / k;
        int index = 0;

        if(size < k)
            return s;

        if(size % k)
        {
            index = size % k;
            s.insert(index, "-");
            index++;
        }

        for(int i = 1; i < num; i++)
        {
            index += k;
            s.insert(index, "-");
            index++;

            // cout << s << endl;
        }

        return s;
    }
};
// @lc code=end

