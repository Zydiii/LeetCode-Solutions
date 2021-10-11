class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        map<int, int> val;
        for(int i = 0; i < arr.size(); i++)
        {
            val[arr[i]] = i;
        }

        vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));
        int result = 2;

        for(int i = 1; i < arr.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                map<int, int>::iterator iter = val.find(arr[i] - arr[j]);            

                if(iter == val.end() || iter->second >= j)
                {
                    dp[i][j] = 2;
                }
                else
                {
                    dp[i][j] = dp[j][iter->second] + 1;

                    result = max(result, dp[i][j]);
                }
            }
        }

        return result > 2 ? result : 0;
    }
};