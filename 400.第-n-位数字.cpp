/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        int bitCount = 0; // 位数
        int result;
        while(true)
        {
            bitCount++;
            long numAll = 9 * pow(10, bitCount - 1);
            //cout << numAll << endl;
            if(n < numAll * bitCount)
            {
                int beginNum = pow(10, bitCount - 1);
                int count  = n / bitCount - 1;
                int remain = n % bitCount;
                //cout << n << endl;
                //cout << bitCount << endl;
                //cout << beginNum << endl;
                //cout << count << endl;
                //cout << remain << endl;
                if(remain == 0)
                {
                    int num = beginNum + count;
                    result = num - (num / 10) * 10;
                    //cout << num << endl;
                }
                else
                {
                    int num = beginNum + count + 1;
                    //cout << num << endl;
                    num = num / pow(10, bitCount - remain);
                    result = num - (num / 10) * 10;
                }
                break;
            }
            else
            {
                n -= numAll * bitCount;
            }
        }
        return result;
    }
};
// @lc code=end

