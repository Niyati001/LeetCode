class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        int n= grid.size();
        int m= grid[0].size();

        vis[row][col]=1;

        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nr= row+ dr[i];
            int nc= col+ dc[i];

            while(nr>=0 && nr< n &&
                  nc>=0 && nc< m &&
                  grid[nr][nc]== '1' && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    dfs(nr, nc, vis, grid);
                  }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int num=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]== '1' && !vis[i][j]){
                    num++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return num;
    }
};