class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        int fresh=0;
        vector<vector<int>> vis(n, vector<int> (m, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j]== 1)
                    fresh++;
                
                else if(grid[i][j]== 2){
                    q.push({{i, j}, 0});
                    vis[i][j]= 1;
                }
            }
        }
        
        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, -1, 0, 1};

        int t=0;

        while(!q.empty()){
            auto curr= q.front();
            q.pop();

            int row= curr.first.first;
            int col= curr.first.second;
            int time= curr.second;
            
            t= max(t, time);

            for(int i=0; i<4; i++){
                int nr= row+ dr[i];
                int nc= col+ dc[i];

                if(nr>=0 && nc>= 0 && nr<n && nc<m && grid[nr][nc]== 1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    fresh--;
                    q.push({{nr, nc}, time+1});
                } 
            }
        }
        if(fresh) return -1;

        return t;
    }
};