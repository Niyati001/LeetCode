class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n= parent.size();

        vector<vector<int>> adj(n);

        for(int i=1; i<n; i++){
            adj[parent[i]].push_back(i);
        }
        vector<int> newParent= parent;
        vector<int> last(26, -1);

         function<void(int)> dfs1= [&](int node) {
            int c= s[node]- 'a';

            int prev= last[c];

            if(prev!= -1 && node!= 0){
                newParent[node]= prev;
            }

            last[c]= node;

            for(int child: adj[node]){
                dfs1(child);
            }

            last[c]= prev;
        };

        dfs1(0);

        vector<vector<int>> finalAdj(n);

        for(int i= 1; i< n; i++){
            finalAdj[newParent[i]].push_back(i);
        }

        vector<int> answer(n, 1);

        function<int(int)> dfs2= [&](int node){
            for(int child: finalAdj[node]){
                answer[node]+= dfs2(child);
            }

            return answer[node];
        };

        dfs2(0);

        return answer;
    }
};