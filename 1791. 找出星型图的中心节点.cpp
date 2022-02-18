class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, vector<int>> edgeMap;
        for(vector<int> edge : edges)
        {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }
        map<int, vector<int>> :: iterator it;
        for(it = edgeMap.begin(); it != edgeMap.end(); it++)
        {
            if(it->second.size() == edges.size())
                return it->first;
        }

        return -1;
    }
};