class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        bool flag = true;
        int j = 0, row = 0;
        vector<vector<char>> map(numRows, vector<char>(s.size(), '#'));
        for(int i = 0; i < s.size(); i++)
        {
            if(flag)
            {
                if(row == numRows - 2)
                {
                    flag = false;
                }
                map[row][j] = s[i];
                row++;
            }
            else
            {
                if(row == 1)
                {
                    flag = true;
                }
                map[row][j] = s[i];
                row--;
                j++;
            }
        }
        string result = "";
        for(int i = 0; i < map.size(); i++)
        {
            for(int j = 0; j < map[0].size(); j++)
            {
                if(map[i][j] != '#')
                    result += map[i][j];
            }
        }
        return result;
    }
};