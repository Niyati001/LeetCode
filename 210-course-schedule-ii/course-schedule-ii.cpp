#include<vector>
#include<queue>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //building graph
        vector<vector<int>> adj(numCourses);
        for(auto &it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        // indegree array
        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(int v: adj[i]){
                indegree[v]++;
            }
        }

        // queue for nodes with indegree 0
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]== 0){
                q.push(i);
            }
        }
        vector<int> topo;

        // kahn's algo
        while(!q.empty()){
        int node= q.front();
        q.pop();
        topo.push_back(node);

        for(int v: adj[node]){
            indegree[v]--;
            if(indegree[v]==0)
            q.push(v);
        }
        }
        if(topo.size()!= numCourses)
           return {};
        return topo;
    }
};