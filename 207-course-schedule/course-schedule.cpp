class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto &p: prerequisites){
            int u= p[0];
            int v= p[1];

            adj[v].push_back(u);
            inDegree[u]++;
        }
        queue<int> q;

        for(int i=0; i< numCourses; i++){
            if(inDegree[i]==0)
                q.push(i);
        }

        int count=0;

        while(!q.empty()){
            int course= q.front();
            q.pop();

            count++;

            for(int next: adj[course]){
                inDegree[next]--;

                if(inDegree[next]==0)
                    q.push(next);
            }
        }
        return count== numCourses;
    }
};