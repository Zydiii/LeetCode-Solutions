class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        for(auto &roll : rolls)
            sum -= roll;
        int meanN = sum / n, remain = sum % n;
        vector<int> result;
        if(sum > 6 * n || sum < n)
            return result;
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(i < remain)
                {
                    result.push_back(meanN + 1);
                }
                else
                {
                    result.push_back(meanN);
                }
            }
        }
        return result;
    }
};