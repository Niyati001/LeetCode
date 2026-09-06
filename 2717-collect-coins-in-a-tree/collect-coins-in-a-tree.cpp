class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // Remove leaves having no coin
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1 && coins[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            // Already removed
            if(degree[u] == 0)
                continue;

            degree[u] = 0;

            for(int v : adj[u]) {
                if(degree[v] == 0)
                    continue;

                degree[v]--;

                if(degree[v] == 1 && coins[v] == 0)
                    q.push(v);
            }
        }

        // Current leaves
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1)
                q.push(i);
        }

        // Remove exactly 2 layers
        for(int step = 0; step < 2; step++) {
            int size = q.size();

            while(size--) {
                int u = q.front();
                q.pop();

                if(degree[u] == 0)
                    continue;

                degree[u] = 0;

                for(int v : adj[u]) {
                    if(degree[v] == 0)
                        continue;

                    degree[v]--;

                    if(degree[v] == 1)
                        q.push(v);
                }
            }
        }

        int ans = 0;

        for(int d : degree)
            ans += d;

        return ans;
    }
};