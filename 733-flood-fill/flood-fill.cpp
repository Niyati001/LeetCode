class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int delRow[], int delCol[], int iniCol){
        ans[row][col]= color;
        int n= image.size();
        int m= image[0].size();

        for(int i=0; i<4; i++){
            int newRow= row+ delRow[i];
            int newCol= col+ delCol[i];

            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && image[newRow][newCol]== iniCol && ans[newRow][newCol]!= color){
                dfs(newRow, newCol, ans, image, color, delRow, delCol, iniCol);
            }

        }
        
    }
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniCol= image[sr][sc];

        vector<vector<int>> ans= image;

        int delRow[]= {-1, 0, 1, 0};
        int delCol[]= {0, 1, 0, -1};

        dfs(sr, sc, ans, image, color, delRow, delCol, iniCol);
        return ans;
    }
};