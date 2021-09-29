/*
 * @lc app=leetcode.cn id=517 lang=cpp
 *
 * [517] 超级洗衣机
 */

// @lc code=start
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int totalSum = accumulate(machines.begin(), machines.end(), 0);
        int totalMachineSum = machines.size();
        if(totalSum % totalMachineSum)
            return -1;
        
        int averageNum = totalSum / totalMachineSum;
        int sum = 0, num = 0;
        int result = 0;
        for(int i = 0; i < totalMachineSum; i++)
        {
            num = machines[i] - averageNum;
            sum += num;
            result = max(result, max(abs(sum), num));
        }

        return result;
    }
};
// @lc code=end

