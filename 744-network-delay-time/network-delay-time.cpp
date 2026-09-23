class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto edge : times){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, 1e9);

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node])
                continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9)
                return -1;

            ans = max(ans, dist[i]);
        }
        return ans;
    }
};