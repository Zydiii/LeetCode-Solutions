class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size(), result = 0;
        vector<int> myK(n, 0);
        for(int i = 0; i < n; i++)
        {
            myK[(i - nums[i] + n + 1) % n]++;
        }
        for(int i = 1; i < n; i++)
        {
            myK[i] += myK[i - 1] - 1;
            if(myK[i] < myK[result])
            {
                result = i;
            }
        }
        return result;
    }
};