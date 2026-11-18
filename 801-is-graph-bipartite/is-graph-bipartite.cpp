class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V= graph.size();

        vector<int> color(V, -1);

        queue<int> q;

        for(int i=0; i<V; i++){
            if(color[i]== -1){
                color[i]=0;
                q.push(i);

                while(!q.empty()){
                    int node= q.front();
                    q.pop();

                    for(auto neig: graph[node]){
                        if(color[neig]== -1){
                            color[neig]=! color[node];
                            q.push(neig);
                        }
                        else if(color[neig]== color[node])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};