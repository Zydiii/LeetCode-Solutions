class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> subset;
        helper(result, subset, s, 0);
        return result;
    }

    void helper(vector<vector<string>> &result, vector<string> &subset, string s, int index)
    {
        if(index == s.length())
        {
            result.push_back(subset);
        }
        else
        {
            for(int i = index; i < s.length(); i++)
            {
                if(isPalindrome(s, index, i))
                {
                    subset.push_back(s.substr(index, i + 1 - index));
                    helper(result, subset, s, i + 1);
                    subset.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        
        while(start < end)
        {

            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }

        return true;
    }
};