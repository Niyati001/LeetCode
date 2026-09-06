class Solution {
public:
    vector<vector<int>> adj;
    vector<int> size;
    vector<int> answer;

    void dfs1(int node, int parent){
        size[node]=1;

        for(int child: adj[node]){
            if(child== parent)
                continue;
            dfs1(child, node);
            
            size[node]+= size[child];
            answer[0]+= size[child];
        }
    }

    void dfs2(int node, int parent, int n){
        for(int child: adj[node]){
            if(child== parent)
                continue;
            answer[child]= answer[node] +n - 2* size[child];

            dfs2(child, node, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        size.resize(n);
        answer.resize(n);

        for(auto edge: edges){
            int u= edge[0];
            int v= edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(0, -1);
        dfs2(0, -1, n);

        return answer;
    }
};