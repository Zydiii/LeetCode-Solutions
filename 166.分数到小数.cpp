/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        numerator = (long)numerator;
        denominator = (long)denominator;

        long division = numerator / denominator;

        string result;
        if(numerator % denominator == 0)
            return to_string(division);
        
        if(numerator < 0 ^ denominator < 0)
            result = "-";
        
        numerator = abs(numerator);
        denominator = abs(denominator);

        long intPart = numerator / denominator;
        result += to_string(intPart);
        result += ".";

        string fractionPart;
        map<long, int> remainDic;
        long remain = numerator % denominator;
        int index = 0;

        while(remain != 0 && !remainDic.count(remain))
        {
            remainDic[remain] = index;
            remain *= 10;
            fractionPart += to_string(remain / denominator);
            remain %= denominator;
            index++;
            
            
            // cout << remain / denominator << " " << remain << endl;
        }

        if(remain != 0)
        {
            int insertIndex = remainDic[remain];
            fractionPart.insert(insertIndex, "(");
            fractionPart += ")";
        }

        result += fractionPart;

        return result;
    }
};
// @lc code=end

