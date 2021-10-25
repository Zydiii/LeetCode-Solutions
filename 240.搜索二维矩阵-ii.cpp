/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, maxColumn = matrix[0].size() - 1;
        for(;row < matrix.size();row++)
        {
            if(target > matrix[row][maxColumn])
            {
                continue;
            }
            else if(target < matrix[row][0])
            {
                return false;
            }
            else
            {
                for(int j = 0; j < matrix[0].size(); j++)
                {
                    if(matrix[row][j] == target)
                        return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

