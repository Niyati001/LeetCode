class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        int fresh=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]== 2){
                    q.push({{i, j}, 0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1) fresh++;
            }
        }

        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};

        int time=0;

        while(!q.empty()){
            auto node= q.front();
            q.pop();

            int row= node.first.first;
            int col= node.first.second;
            int t= node.second;

            time= max(time, t);

        for(int i=0; i<4; i++){
            int nr= row+ dr[i];
            int nc= col+ dc[i];

            while(nr>=0 && nr< n &&
                  nc>=0 && nc< m &&
                  !vis[nr][nc] &&
                  grid[nr][nc]== 1){
                    vis[nr][nc]=1;
                    q.push({{nr, nc}, t+1});
                  }
        }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]== 1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return time;
    }
};