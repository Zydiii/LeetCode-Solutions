class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stacks;
        for(int as : asteroids)
        {
            while(!stacks.empty() && stacks.top() > 0 && stacks.top() < -as)
            {
                stacks.pop();
            }
            if(!stacks.empty() && as < 0 && stacks.top() == -as)
                stacks.pop();
            else if(stacks.empty() || as > 0 || stacks.top() < 0)
                stacks.push(as);
        }
        vector<int> result(stacks.size());
        int i = stacks.size() - 1;
        while(!stacks.empty())
        {
            result[i] = stacks.top();
            stacks.pop();
            i--;
        }
        return result;
    }
};