/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> charMap;
        for(char c: secret)
        {
            if(charMap.find(c) != charMap.end())
            {
                charMap[c]++;
            }
            else
            {
                charMap[c] = 1;
            }
        }

        int bulls = 0, cows = 0;
        for(int i = 0; i < guess.size(); i++)
        {
            if(guess[i] == secret[i])
            {
                bulls++;
                charMap[guess[i]]--;
            }
        }

        for(int i = 0; i < guess.size(); i++)
        {
            if(guess[i] != secret[i] && charMap[guess[i]] > 0)
            {
                cows++;
                charMap[guess[i]]--;             
            }
        }

        return  to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
// @lc code=end

