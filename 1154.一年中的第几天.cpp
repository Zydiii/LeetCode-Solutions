/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */

// @lc code=start
class Solution {
public:
    int dayOfYear(string date) {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        bool flag = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        //cout << day << " " << month << " " << year << endl;
        //cout << flag << endl;
        int num = 0;
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 0; i < month - 1; i++)
        {
            num += days[i];
        }
        num += day;
        if(flag && month > 2)
            num += 1;
        return num;
    }
};
// @lc code=end

