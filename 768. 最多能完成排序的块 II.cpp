class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int, int> cnt;
        int res = 0;
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        for (int i = 0; i < sortedArr.size(); i++) {
            int x = arr[i], y = sortedArr[i];
            cnt[x]++;
            if (cnt[x] == 0) {
                cnt.erase(x);
            }
            cnt[y]--;
            if (cnt[y] == 0) {
                cnt.erase(y);
            }
            if (cnt.size() == 0) {
                res++;
            }
        }
        return res;
    }
};