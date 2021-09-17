/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRow(board) && checkColumn(board) && checkBlock(board);
    }

    bool checkRow(vector<vector<char>>& board)
    {
        vector<vector<int>> mask(9, vector<int>(9));

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    mask[i][board[i][j] - '0' - 1]++;

                    if(mask[i][board[i][j] - '0' - 1] > 1)
                        return false;
                }
            }
        }

        return true;
    }

    bool checkColumn(vector<vector<char>>& board)
    {
        vector<vector<int>> mask(9, vector<int>(9));

        for(int j = 0; j < 9; j++)
        {
            for(int i = 0; i < 9; i++)
            {
                if(board[i][j] != '.')
                {
                    mask[j][board[i][j] - '0' - 1]++;

                    if(mask[j][board[i][j] - '0' - 1] > 1)
                        return false;
                }
            }
        }

        return true;
    }

    bool checkBlock(vector<vector<char>>& board)
    {
        vector<vector<int>> direction {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
        vector<vector<int>> mask(9, vector<int>(9));
        int count  = 0;

        for(int i = 1; i < 9; i += 3)
        {
            for(int j = 1; j < 9; j+= 3)
            {
                if(board[i][j] != '.')
                {
                    mask[count][board[i][j] - '0' - 1]++;
                }
                for(vector<int> dir : direction)
                {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(board[new_i][new_j] != '.')
                    {
                        mask[count][board[new_i][new_j] - '0' - 1]++;

                        if(mask[count][board[new_i][new_j] - '0' - 1] > 1)
                            return false;
                    }
                }
                count++;
            }
        }

        return true;
    }
};
// @lc code=end

