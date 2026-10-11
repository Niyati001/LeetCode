class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& suspicious){
        suspicious[node]= true;

        for(int next: adj[node]){
            if(!suspicious[next])
               dfs(next, adj, suspicious);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto &edge: invocations){
            int u= edge[0];
            int v= edge[1];
            adj[u].push_back(v);
        }
        vector<bool> suspicious(n, false);
        dfs(k, adj, suspicious);

        for(auto &edge: invocations){
            int a= edge[0];
            int b= edge[1];

            if(!suspicious[a] && suspicious[b]){
                vector<int> allMethods;

                for(int i=0; i<n; i++){
                    allMethods.push_back(i);
                }
                return allMethods;
            }
        }

        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!suspicious[i])
               ans.push_back(i);
        }
        return ans;
    }
};