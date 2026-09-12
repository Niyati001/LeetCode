class Solution {
public:
    vector<int> parent, rankv;

    int find(int x){
        if(parent[x]== x) return x;

        return parent[x]= find(parent[x]);
    }

    bool unite(int a, int b){
        a= find(a);
        b= find(b);

        if(a==b) return false;

        if(rankv[a]< rankv[b])
            swap(a, b);
        
        parent[b]= a;

        if(rankv[a]== rankv[b])
            rankv[a]++;
        
        return true;
    }
      
    bool possible(int n, vector<vector<int>>& edges, int k, int t){
        parent.resize(n);
        rankv.assign(n, 0);

        for(int i=0; i<n; i++)
            parent[i]=i;

        int components= n;

        for(auto &edge: edges){
            int u= edge[0];
            int v= edge[1];
            int time= edge[2];

            if(time> t){
                if(unite(u, v))
                    components--;
            }
        }
        return components>= k;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        int low=0;
        int high=0;

        for(auto &edge: edges)
            high= max(high, edge[2]);

        while(low<high){
            int mid= low+ (high- low)/2;

            if(possible(n, edges, k, mid))
                high= mid;
            else
                low= mid+1;
        }
        return low;
    }
};