class Solution {
public:
    vector<int> parent, rank;

    int find(int node){
        if(parent[node]== node) return node;
        return parent[node]= find(parent[node]);
    }

    void Union(int u, int v){
        int pu= find(u);
        int pv= find(v);

        if(pu== pv) return;

        if(rank[pu]< rank[pv])
            parent[pu]= pv;

        else if(rank[pu]> rank[pv])
            parent[pv]= pu;
        
        else{
            parent[pv]= pu;
            rank[pu]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()< n-1)
            return -1;
        
        parent.resize(n);
        rank.assign(n, 0);

        for(int i=0; i<n; i++){
            parent[i]= i;
        }

        for(auto edge: connections){
            Union(edge[0], edge[1]);
        }

        int components=0;

        for(int i=0; i< n; i++){
            if(find(i)==i)
                components++;
        }
        return components-1;
    }
};