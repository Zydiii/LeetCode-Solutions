class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m, vector<int>(n));
        for(auto pair : indices){
            int ri = pair[0], ci = pair[1];
            for(int j = 0; j < n; j++)
                matrix[ri][j]++;
            for(int i = 0; i < m; i++)
                matrix[i][ci]++;
        }

        int sum = 0;
        for(auto &nums : matrix)
        {
            for(int num : nums){
                if(num % 2)
                    sum++;
            }     
        }

        return sum;
    }
};