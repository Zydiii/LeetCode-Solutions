class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxLength(answerKey, k, 'T'), maxLength(answerKey, k, 'F'));
    }

    int maxLength(string key, int k, char flag)
    {
        int result = 0, sum = 0;
        for(int left = 0, right = 0; right < key.size(); right++)
        {
            sum += key[right] == flag ? 0 : 1;
            while(sum > k)
            {
                sum -= key[left] == flag ? 0 : 1;
                left++;
            }
            result = max(result, right - left + 1);
        }

        return result;
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};