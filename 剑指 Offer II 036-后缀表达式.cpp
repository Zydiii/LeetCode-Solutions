class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stacks;
        for(string s : tokens)
        {
            if(s == "+" || s == "-" || s == "*" || s == "/")
            {
                int a = stacks.top();
                stacks.pop();
                int b = stacks.top();
                stacks.pop();
                stacks.push(getValue(b, a, s));
            }
            else
            {
                stacks.push(stoi(s));
            }
        }
        return stacks.top();
    }

    int getValue(int a, int b, string s)
    {
        if(s == "+")
            return a + b;
        if(s == "-")
            return a - b;
        if(s == "*")
            return a * b;
        if(s == "/")
            return a / b;
        return 0;
    }
};