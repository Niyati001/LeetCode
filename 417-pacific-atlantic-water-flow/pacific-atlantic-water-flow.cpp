class Solution {
public:
    int m, n;

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& vis){
        vis[r][c]=1;

        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nr= r+ dr[i];
            int nc= c+ dc[i];

            if(nr>=0 && nr<m &&
               nc>=0 && nc<n &&
               !vis[nr][nc] && heights[nr][nc]>= heights[r][c]){
                dfs(nr, nc, heights, vis);
               }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m= heights.size();
        n= heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            dfs(i, 0, heights, pacific);
            dfs(i, n-1, heights, atlantic);
        }

        for(int j=0; j<n; j++){
            dfs(0, j, heights, pacific);
            dfs(m-1, j, heights, atlantic);
        }

        vector<vector<int>> ans;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};