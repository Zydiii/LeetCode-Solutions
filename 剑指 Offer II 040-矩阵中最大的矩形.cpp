class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        vector<int> heights(matrix[0].size());
        int result = 0;
        for(string s : matrix)
        {
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == '0')
                    heights[i] = 0;
                else 
                    heights[i]++;
            }
            result = result > calArea(heights) ? result : calArea(heights);
        }
        return result;
    }

    int calArea(vector<int> heights)
    {
        stack<int> h;
        h.push(-1);
        int result = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            while(!h.empty() && h.top() != -1 && heights[i] <= heights[h.top()])
            {
                int height = heights[h.top()];
                h.pop();
                int width = i - h.top() - 1;
                result = result > height * width ? result : height * width;
            }
            h.push(i);            
        }

        while(!h.empty() && h.top() != -1)
        {
            int height = heights[h.top()];
            h.pop();
            int width = heights.size() - h.top() - 1;
            result = result > height * width ? result : height * width;
        }

        return result;
    }
};