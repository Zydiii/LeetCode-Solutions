class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int a : arr)
            map[a]++;
        if(map[0] % 2)
            return false;

        vector<int> ans;
        for(auto &[x, _] : map)
            ans.push_back(x);
        
        sort(ans.begin(), ans.end(), [](int a, int b) {return abs(a) < abs(b);});
        for(auto &a : ans)
        {
            if(map[a] > map[2 * a])
                return false;
            map[2 * a] -= map[a];
        }

        return true;
    }
};