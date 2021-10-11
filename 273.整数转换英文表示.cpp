/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution {
    vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string result;
        for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000) {
            int curNum = num / unit;
            if (curNum != 0) {
                num -= curNum * unit;
                result += getWords(curNum) + thousands[i] + " ";
            }
        }
        while (result.back() == ' ') {
            result.pop_back();
        }
        return result;

    }

    string getWords(int n)
    {
        if(n == 0)
            return "";
        else if(n < 10)
            return singles[n] + " ";
        else if(n < 20)
            return teens[n - 10] + " ";
        else if(n < 100)
            return tens[n / 10] + " " + getWords(n % 10);
        else
            return singles[n / 100] + " Hundred " + getWords(n % 100);
    }
};
// @lc code=end

