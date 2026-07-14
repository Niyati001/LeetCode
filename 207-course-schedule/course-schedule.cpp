class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>inDegree(numCourses, 0);

        for(auto edge: prerequisites){
            int u= edge[1];
            int v= edge[0];
            
            adj[u].push_back(v);
            inDegree[v]++;
        }
        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0)
                q.push(i);
        }
        int count=0;
        
        while(!q.empty()){
            int node= q.front();
            q.pop();

            count++;
            for(auto neigh: adj[node]){
                inDegree[neigh]--;

                if(inDegree[neigh]==0) q.push(neigh);
            }
        }
        return count== numCourses;
    }
};