class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(auto &edge: edges){
            int u= edge[0];
            int v= edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ans= INT_MAX;

        for(int src=0; src<n; src++){
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);

            queue<int> q;

            dist[src]=0;
            q.push(src);

            while(!q.empty()){
                int node= q.front();
                q.pop();

                for(int next: graph[node]){
                    //first time visiting edge
                    if(dist[next]== -1){
                        dist[next]= dist[node]+1;
                        parent[next]= node;
                        q.push(next);
                    }

                    // already visited and not the parent
                    else if(parent[node]!= next){
                        ans= min(ans, dist[node]+ dist[next]+ 1);
                    }
                }
            }
        }
        return ans== INT_MAX? -1: ans;
    }
};