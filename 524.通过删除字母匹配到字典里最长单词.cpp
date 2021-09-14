/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int maxLong = 0;
        string maxString = "";

        for(int i = 0; i < dictionary.size(); i++)
        {
            string dic = dictionary[i];
            int index = -1;
            int size = 0;

            for(int j = 0; j < dic.length(); j++)
            {
                for(int k = index + 1;  k < s.length(); k++)
                {
                    if(s[k] == dic[j])
                    {
                        index = k;
                        size++;
                        break;
                    }
                }
            }

            if(size == dic.length())
            {
                if(dic.length() == maxLong)
                {
                    for(int l = 0; l < dic.length(); l++)
                    {
                        if(dic[l] < maxString[l])
                        {
                            maxLong = dic.length();
                            maxString = dic;
                            break;
                        }
                        else if(dic[l] == maxString[l])
                        {
                            continue;
                        }
                        else
                            break;
                    }
                }
                else if(dic.length() > maxLong)
                {
                    maxLong = dic.length();
                    maxString = dic;
                }
            }
            
        }

        return maxString;
        
    }
};
// @lc code=end

