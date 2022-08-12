class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> cache;
        vector<vector<int>> result;
        int index = 0;
        for(auto &size : groupSizes){
            if(cache.find(size) != cache.end()){
                cache[size].push_back(index);
            }
            else{
                cache[size].emplace_back(index);
            }
            if(cache[size].size() == size){
                    result.push_back(cache[size]);
                    cache.erase(size);
                }
            index++;
        }
        return result;
    }
};