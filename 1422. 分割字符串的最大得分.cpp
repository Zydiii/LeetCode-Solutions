class Solution {
public:
    int maxScore(string s) {
        int result = 0, score = 0;
        if(s[0] == '0')
            score = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '1')
                score++;
        }
        result = score;
        for(int i = 1; i < s.size() - 1; i++){
            if(s[i] == '0')
               score++;
            else
               score--;
            result = max(result, score);
        }
        return result;
    }
};