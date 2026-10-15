class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        vector<int> ans(n, 0);

        // First DFS: calculate reversals needed from node 0
        function<void(int, int)> dfs1 = [&](int u, int parent) {
            for (auto [v, cost] : adj[u]) {
                if (v == parent) continue;

                ans[0] += cost;
                dfs1(v, u);
            }
        };

        dfs1(0, -1);

        // Second DFS: reroot from parent u to child v
        function<void(int, int)> dfs2 = [&](int u, int parent) {
            for (auto [v, cost] : adj[u]) {
                if (v == parent) continue;

                ans[v] = ans[u] + (cost == 0 ? 1 : -1);
                dfs2(v, u);
            }
        };

        dfs2(0, -1);

        return ans;
    }
};
