class Solution {
public:
    string reverseOnlyLetters(string s) {
        int index = s.size() - 1;
        string result = s;
        for(int i = 0; i < index; i++)
        {
            if(!isChar(s[i]))
            {
                continue;
            }
            while(!isChar(s[index]))
            {
                index--;
            }
            result[i] = s[index];
            result[index] = s[i];
            index--;
        }
        return result;
    }

    bool isChar(char s)
    {
        return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z');
    }
};