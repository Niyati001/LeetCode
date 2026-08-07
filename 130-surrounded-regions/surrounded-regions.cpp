class Solution {
public:
    int m, n;
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[row][col]=1;

        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nr= row+ dr[i];
            int nc= col+ dc[i];

            if(nr>=0 && nr<m &&
               nc>=0 && nc<n &&
               !vis[nr][nc] && board[nr][nc]== 'O'){
                dfs(nr, nc, board, vis);
               }
        }
    }

    void solve(vector<vector<char>>& board) {
        m= board.size();
        n= board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            if(board[i][0]== 'O')
                dfs(i, 0, board, vis);
            
            if(board[i][n-1]== 'O')
                dfs(i, n-1, board, vis);
        }

        for(int j=0; j<n; j++){
            if(board[0][j]== 'O')
                dfs(0, j, board, vis);
            
            if(board[m-1][j]== 'O')
                dfs(m-1, j, board, vis);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]== 'O' && !vis[i][j]){
                    board[i][j]= 'X';
                }
            }
        }   
    }
};