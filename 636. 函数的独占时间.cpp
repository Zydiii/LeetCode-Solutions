class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n);
        stack<pair<int, int>> func;
        for(auto &log : logs){
            int id = stoi(log.substr(0, log.find(':')));
            int time = stoi(log.substr(log.rfind(':') + 1));
            string state = log.substr(log.find(':') + 1, log.rfind(':') - log.find(':') - 1);
            if(state == "start"){
                if(!func.empty()){
                    result[func.top().first] += time - func.top().second;
                    func.top().second = time;
                }
                func.emplace(id, time);
            }
            else{
                pair<int, int> p = func.top();
                func.pop();
                result[p.first] += time - p.second + 1;
                if(!func.empty()){
                    func.top().second = time + 1;
                }
            }
        }
        return result;
    }
};