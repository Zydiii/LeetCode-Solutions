class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int> m1, m2;
        for(int i{0}; i < target.size(); ++i){
            m1[target[i]]++;
            m2[arr[i]]++;
        }
        for(auto &m : m1){
            if(m2[m.first] != m.second)
                return false;
        }
        return true;
    }
};