class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> t;
        for(int i = 0; i < temperatures.size(); i++)
        {
            int temp = temperatures[i];
            while(!t.empty() && temp > temperatures[t.top()])
            {
                int index = t.top();
                t.pop();
                result[index] = i - index;
            }
            t.push(i);
        }
        return result;
    }
};