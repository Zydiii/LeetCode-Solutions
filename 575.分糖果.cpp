/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> types;
        for(int i = 0; i < candyType.size(); i++)
        {
            types.insert(candyType[i]);
        }
        int typeNum = types.size();
        cout << typeNum << endl;
        if(candyType.size() / 2 > typeNum)
            return typeNum;
        else
            return candyType.size() / 2;
    }
};
// @lc code=end

