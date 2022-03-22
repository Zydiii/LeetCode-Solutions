class Solution {
public:
    bool winnerOfGame(string colors) {
        int result[2] = {0, 0};
        char cur = 'C';
        int cnt = 0;
        for(char c : colors)
        {
            if(c != cur)
            {
                cur = c;
                cnt = 1;
            }
            else
            {
                cnt++;
                if(cnt >= 3)
                    result[cur - 'A']++;
            }
        }
   
        return result[0] > result[1];
    }
};
