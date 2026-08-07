class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto edge: prerequisites){
            int u= edge[1];
            int v= edge[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0; i< numCourses; i++){
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);

            for(auto neigh: adj[node]){
                indegree[neigh]--;

                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        if(ans.size()== numCourses) return ans;
        return {};
    }
};