class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        int n = abs(num);
        string result;
        while(n != 0)
        {
            result = to_string(n % 7) + result;
            n /= 7;
        }
        return num >= 0 ? result : "-" + result;
    }
};