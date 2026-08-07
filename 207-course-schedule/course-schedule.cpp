class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto edge: prerequisites){
            int u= edge[0];
            int v= edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i=0; i< numCourses; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;

        while(!q.empty()){
            int node= q.front();
            q.pop();

            count++;

            for(auto neigh: adj[node]){
                indegree[neigh]--;

                if(indegree[neigh]== 0)
                    q.push(neigh);

            }
        }
        return count== numCourses;
    }
};