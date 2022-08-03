class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        else{
            string result = s;
            for(int i{1}; i < s.size(); ++i){
                char c = s[0];
                s = s.substr(1);
                s.push_back(c);
                if(s < result){
                    result = s;
                }
            }
            return result;
        }
    }
};