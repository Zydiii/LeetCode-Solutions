class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for(auto &edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        queue<int> q;
        q.emplace(0);
        visit[0] = true;
        int dist = 1, ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                for(auto &v : adj[curr])
                {
                    if(!visit[v])
                    {
                        q.emplace(v);
                        int time = patience[v] * ((2 * dist - 1) / patience[v]) + 2 * dist + 1;
                        ans = max(ans, time);
                        visit[v] = true;
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};
