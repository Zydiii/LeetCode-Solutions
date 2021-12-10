/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);
        vector<int> chars(24);
        cout << licensePlate << endl;
        for(char c : licensePlate)
        {
            if(c >= 'a' && c <= 'z')
                chars[c - 'a']++;
        }

        string result;
        for(string word : words)
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            vector<int> wordsChars(24);
            for(char c : word)
            {
                if(c >= 'a' && c <= 'z')
                    wordsChars[c - 'a']++;
            }
            int flag = true;
            for(int i = 0; i < 24; i++)
            {
                if(chars[i] == 0)
                    continue;
                if(chars[i] > wordsChars[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag && (result.size() == 0 || result.size() > word.size()))
                result = word;
        }
        return result;
    }
};
// @lc code=end

