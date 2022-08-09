class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int result = INT_MIN;
        for(auto &num : nums){
            sum += num;
            result = max(max(1 - sum, result), 1);
        }
        return result;
    }
};