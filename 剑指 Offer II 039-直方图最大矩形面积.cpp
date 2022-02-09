class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> height;
        height.push(-1);
        int result = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            int h = heights[i];
            while(height.top() != -1 && h <= heights[height.top()])
            {
                int maxHeight = heights[height.top()];
                height.pop();
                int width = i - height.top() - 1;
                result = result > maxHeight * width ? result : maxHeight * width;
            }
            height.push(i);
        }
        while(height.top() != -1)
        {
            int maxHeightIndex = height.top();
            int maxHeight = heights[maxHeightIndex];
            height.pop();
            int width = heights.size() - height.top() - 1;
            result = result > maxHeight * width ? result : maxHeight * width;
        }
        return result;
    }
};