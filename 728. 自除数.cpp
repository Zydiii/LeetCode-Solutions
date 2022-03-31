class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left; i <= right; i++)
        {
            if(isValid(i))
                result.push_back(i);
        }
        return result;
    }

       
    bool isValid(int num)
    {
        int n = num;
        while(n > 0)
        {
            int digit = n % 10;
            if(digit == 0 || num % digit != 0 )
                return false;
            n /= 10;
        }
        return true;
    }
};