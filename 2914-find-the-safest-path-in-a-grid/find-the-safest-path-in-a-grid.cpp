class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n= grid.size();

        vector<vector<int>>dist(n, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                    dist[i][j]=0;
                }
            }
        }
        int dr[]= {-1, 1, 0, 0};
        int dc[]= {0, 0, -1, 1};

        while(!q.empty()){
            auto [r, c]= q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int nr= r+ dr[k];
                int nc= c+ dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc]==-1){
                    dist[nr][nc]= dist[r][c]+ 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<tuple<int, int, int>> pq;

        vector<vector<int>> best(n, vector<int>(n, -1));

        best[0][0]= dist[0][0];

        pq.push({best[0][0], 0, 0});

        while(!pq.empty()){
            auto [safe, r, c]= pq.top();
            pq.pop();

            if(r== n-1 && c== n-1)
                return safe;

            if(safe< best[r][c]){
                continue;
            }

            for(int k=0; k<4; k++){
                int nr= r+ dr[k];
                int nc= c+ dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int newSafe= min(safe, dist[nr][nc]);

                    if(newSafe> best[nr][nc]){
                        best[nr][nc]= newSafe;
                        pq.push({newSafe, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};