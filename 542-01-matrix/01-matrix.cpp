class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int> (n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int dr[]= {-1, 1, 0, 0};
        int dc[]= {0, 0, -1, 1};

        //push all zeros
        for(int i=0; i< m; i++){
            for(int j=0; j< n; j++){
                if(mat[i][j]== 0){
                    q.push({i,j});
                    visited[i][j]= true;
                }
            }
        }
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();

            for(int k=0; k<4; k++){
                int newRow= row+ dr[k];
                int newCol= col+ dc[k];

                if(newRow>=0 && newRow< m &&
                newCol>=0 && newCol< n &&
                !visited[newRow][newCol]){
                    visited[newRow][newCol]= true;
                    dist[newRow][newCol]= dist[row][col]+1;
                    q.push({newRow, newCol});

                }
            }
        }
        return dist;
    }
};