class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> subset;

        combineReverse(result, subset, n, 1, k);

        return result;
    }

    void combineReverse(vector<vector<int>> &result, vector<int> &subset, int n, int index, int k)
    {
        if(subset.size() == k)
        {
            result.push_back(subset);
        }
        else if(index <= n)
        {
            combineReverse(result, subset, n, index + 1, k);

            subset.push_back(index);
            combineReverse(result, subset, n, index + 1, k);

            subset.pop_back();
        }
    }
};