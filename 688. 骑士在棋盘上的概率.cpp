class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, -2}, {1, 2}, {-1, 2}, {-1, -2}};
        vector<vector<vector<double>>> dps(k + 1, vector<vector<double>>(n, vector<double>(n)));
        for(int s = 0; s <= k; s++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(s == 0)
                        dps[s][i][j] = 1;
                    else
                    {
                        for(auto &dir : dirs)
                        {
                            int stepi = dir[0] + i;
                            int stepj = dir[1] + j;
                            if(stepi >= 0 && stepi < n && stepj >= 0 && stepj < n)
                            {
                                dps[s][i][j] += dps[s - 1][stepi][stepj] / 8;
                            }
                        }
                    }
                }
            }
        }
        return dps[k][row][column];
    }
};