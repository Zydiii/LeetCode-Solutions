class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> subset;

        helper(candidates, result, subset, target, 0);

        return result;
    }

    void helper(vector<int>& candidates, vector<vector<int>>& result, vector<int>& subset, int target, int index)
    {
        if(target == 0)
            result.push_back(subset);
        else if(target > 0 && index < candidates.size())
        {
            if(getNext(candidates, index) != -1)
            {
                helper(candidates, result, subset, target, getNext(candidates, index));
            }

            subset.push_back(candidates[index]);
            helper(candidates, result, subset, target - candidates[index], index + 1);

            subset.pop_back();
        }
    }

    int getNext(vector<int>& candidates, int index)
    {
        for(int i = index; i < candidates.size(); i++)
        {
            if(candidates[i] != candidates[index])
                return i;
        }

        return -1;
    }
};