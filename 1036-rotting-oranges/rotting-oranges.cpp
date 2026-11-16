class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        queue<pair<pair<int, int>, int>>q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int fresh=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)
                    fresh++;
                else if(grid[i][j]== 2){
                    q.push({{i, j}, 0});
                    vis[i][j]= 1;
                }
            }
        }
        int time=0;

        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};

        while(!q.empty()){
            auto node= q.front();
            q.pop();

            int r= node.first.first;
            int c= node.first.second;
            int t= node.second;

            time= max(t, time);

            for(int i=0; i<4; i++){
                int nr= r+ dr[i];
                int nc= c+ dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]== 1){
                    vis[nr][nc]=1;
                    q.push({{nr, nc}, t+1});
                }
            }
        }
            for(auto row: vis){
                for(auto x: row){

                }
            }

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j]== 1 && !vis[i][j])
                        return -1;
                }
            }
            return time;
    }
};