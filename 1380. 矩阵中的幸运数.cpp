class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        map<int, int> row;
        map<int, int> col;
        for(int i = 0; i < matrix.size(); i++)
        {
            int minIndex = 0;
            for(int j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] < matrix[i][minIndex])
                    minIndex = j;
            }
            row[i] = minIndex;
        }
        for(int j = 0; j < matrix[0].size(); j++)
        {
            int maxIndex = 0;
            for(int i = 1; i < matrix.size(); i++)
            {
                if(matrix[i][j] > matrix[maxIndex][j])
                    maxIndex = i;
            }
            col[j] = maxIndex;
        }

        map<int, int>:: iterator it = row.begin();
        while(it != row.end())
        {
            if(col[it->second] == it->first)
                result.push_back(matrix[it->first][it->second]);
            it++;
        }

        return result;
    }
};