class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int size = requests.size(), result = 0;
        for(int mask = 0; mask < (1 << size); mask++)
        {
            int cnt = __builtin_popcount(mask);
            if(cnt < result)
                continue;
            vector<int> r(n);
            for(int i = 0; i < size; i++)
            {
                if(mask & (1 << i))
                {
                    r[requests[i][0]]--;
                    r[requests[i][1]]++;
                }
            }
            if(all_of(r.begin(), r.end(), [](int i) {return i == 0;}))
            {
                result = cnt;
            }
            
        }
        return result;
    }
};

