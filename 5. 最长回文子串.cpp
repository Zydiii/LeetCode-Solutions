#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1){
            return s;
        }

        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }

        int max = 1;
        int index = 0;
        for(int k = 1; k <= n; k++){
            for(int i = 0; i < n - 1; i++){
                int j = i + k;
                if(j > n - 1)
                    break;
                if(s[i] != s[j]) {
                    dp[i][j] = false;
                }
                else {
                    if(j <= i + 2)
                        dp[i][j] = true;
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    if(dp[i][j] && k + 1 > max) {
                        max = k + 1;
                        index = i;
                    }
                }
            }
        }

        return s.substr(index, max);
    }
};
