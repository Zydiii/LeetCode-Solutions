/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int XCount = 0, OCount = 0;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == 'X')
                    XCount++;
                else if(board[i][j] == 'O')
                    OCount++;
            }
        }

        if(XCount != OCount && XCount != OCount + 1)
            return false;  
        if(win(board, 'X') && XCount != OCount + 1)
            return false;
        if(win(board, 'O') && XCount != OCount)
            return false;
        if(win(board, 'X') && win(board, 'O'))
            return false;
        return true;

    }
    bool win(vector<string>& board, char c)
    {
        for(int i = 0; i < board.size(); i++)
        {
            if(board[i][0] == c && board[i][1] == c && board[i][2] == c)
            {
                return true;
            }
            if(board[0][i] == c && board[1][i] == c && board[2][i] == c)
            {
                return true;
            }
        }
        if(board[0][0] == c && board[1][1] == c && board[2][2] == c)
            return true;
        if(board[0][2] == c && board[1][1] == c && board[2][0] == c)
            return true;
        return false;
    }
};
// @lc code=end

