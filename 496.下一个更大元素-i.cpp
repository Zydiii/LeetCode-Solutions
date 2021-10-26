/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> checkMap;
        stack<int> maxStack;

        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            int num = nums2[i];
            while(!maxStack.empty() && num >= maxStack.top())
                maxStack.pop();
            checkMap[num] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.push(num);
        }

        vector<int> result;
        for(int i = 0; i < nums1.size(); i++)
            result.push_back(checkMap[nums1[i]]);
        
        return result;
    }
};
// @lc code=end

