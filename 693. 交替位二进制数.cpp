class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n % 2;
        while(n != 0)
        {
            n /= 2;
            if(last == n % 2)
                return false;
            last = n % 2;
        }
        return true;
    }
};