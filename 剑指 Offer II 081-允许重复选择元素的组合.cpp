class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> sumSub;

        reverse(result, candidates, sumSub, target, 0);

        return result;
    }

    void reverse(vector<vector<int>>& result, vector<int>& candidates, vector<int>& sumSub, int target, int index)
    {
        if(target == 0)
            result.push_back(sumSub);
        else if(target > 0 && index < candidates.size())
        {
            reverse(result, candidates, sumSub, target, index + 1);
            sumSub.push_back(candidates[index]);
            reverse(result, candidates, sumSub, target - candidates[index], index);
            sumSub.pop_back();
        }
    }
};