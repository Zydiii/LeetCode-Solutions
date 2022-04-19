class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> result(n);
        for(int i = 0, index = -n; i < n;i++) {
            if(s[i] == c) {
                index = i;
            }
            result[i] = i - index;
        }
        for (int i = n - 1, index = 2 * n; i >= 0; i--) {
            if (s[i] == c) {
                index = i;
            }
            result[i] = min(result[i], index - i);
        }
        return result;
    }
};
