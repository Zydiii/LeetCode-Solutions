class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> result(grid[0].size(), -1);
        for(int j = 0; j < grid[0].size(); j++)
        {
            int col = j;
            for(auto &row : grid)
            {
                int dir = row[col];
                col += dir;
                if(col == -1 || col == grid[0].size() || dir != row[col])
                {
                    col = -1;
                    break;
                }
            }
            result[j] = col;
        }
        return result;
    }
};