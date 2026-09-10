class Solution {
public:
    vector<vector<pair<int, int>>>adj;
    vector<int> answer;

    void dfs1(int node, int parent){
        for(auto [next, cost]: adj[node]){
            if(next== parent)
                continue;
            answer[0]+= cost;
            dfs1(next, node);
        }
    }

    void dfs2(int node, int parent){
        for(auto [next, cost]: adj[node]){
            if(next== parent) continue;

            if(cost==0)
                answer[next]= answer[node]+1;
            else
                answer[next]= answer[node]-1;
            
            dfs2(next, node);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        answer.assign(n, 0);

        for(auto &e: edges){
            int u= e[0];
            int v= e[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }
        dfs1(0, -1);
        dfs2(0, -1);
       
       return answer;
    }
};