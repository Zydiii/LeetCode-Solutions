class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(auto as : asteroids){
            bool flag = true;
            while(flag && result.size() > 0 && as < 0 && result.back() > 0){
                flag = result.back() < -as;
                if(result.back() <= -as){
                    result.pop_back();
                }
            }

            if(flag)
                result.push_back(as);
        }
        return result;
    }
};