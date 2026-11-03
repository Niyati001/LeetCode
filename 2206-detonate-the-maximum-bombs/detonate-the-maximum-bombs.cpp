class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int &count){
        visited[node]= true;
        count++;

        for(int next: adj[node]){
            if(!visited[next])
                dfs(next, adj, visited, count);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n= bombs.size();

        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;

                long long dx= bombs[i][0]- bombs[j][0];
                long long dy= bombs[i][1]- bombs[j][1];
                long long r= bombs[i][2];

                if(dx*dx+ dy*dy<= r*r)
                    adj[i].push_back(j);
            }
        }

        int ans=0;

        for(int i=0; i<n; i++){
            vector<bool> visited(n, false);
            int count=0;

            dfs(i, adj, visited, count);
            ans= max(ans, count);
        }
        return ans;
    }
};