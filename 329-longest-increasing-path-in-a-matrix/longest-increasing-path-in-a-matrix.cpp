class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (dp[r][c] != -1)
            return dp[r][c];

        int ans = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (matrix[nr][nc] > matrix[r][c]) {
                ans = max(ans, 1 + dfs(matrix, nr, nc));
            }
        }

        return dp[r][c] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                ans = max(ans, dfs(matrix, r, c));
            }
        }

        return ans;
    }
};