class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1)
            return true;
        if(isupper(word[0]))
        {
            if(isupper(word[1]))
            {
                for(int i = 2; i < word.size(); i++)
                {
                    if(islower(word[i]))
                        return false;
                }
            }
            else
            {
                for(int i = 2; i < word.size(); i++)
                {
                    if(isupper(word[i]))
                        return false;
                }
            }
        }
        else
        {
            for(char c : word)
            {
                if(isupper(c))
                    return false;
            }
        }
        return true;
    }
};