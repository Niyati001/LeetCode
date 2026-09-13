class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return 0;

        if (grid[r][c] != 1)
            return 0;

        // Mark as stable
        grid[r][c] = 2;

        int count = 1;

        count += dfs(grid, r + 1, c);
        count += dfs(grid, r - 1, c);
        count += dfs(grid, r, c + 1);
        count += dfs(grid, r, c - 1);

        return count;
    }

    vector<int> hitBricks(vector<vector<int>>& grid,
                          vector<vector<int>>& hits) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> original = grid;

        // Apply all hits
        for (auto& hit : hits) {
            int r = hit[0];
            int c = hit[1];

            if (grid[r][c] == 1)
                grid[r][c] = 0;
        }

        // Mark all bricks currently connected to the top
        for (int c = 0; c < n; c++) {
            if (grid[0][c] == 1)
                dfs(grid, 0, c);
        }

        vector<int> result(hits.size());

        // Reverse the hits
        for (int i = hits.size() - 1; i >= 0; i--) {

            int r = hits[i][0];
            int c = hits[i][1];

            // No brick existed here originally
            if (original[r][c] == 0) {
                result[i] = 0;
                continue;
            }

            // Add the brick back
            grid[r][c] = 1;

            // Is it connected to the stable component?
            bool connectedToStable = (r == 0);

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 2) {

                    connectedToStable = true;
                    break;
                }
            }

            if (!connectedToStable) {
                // IMPORTANT:
                // Keep this brick as 1.
                // It may become stable later.
                result[i] = 0;
                continue;
            }

            // This brick connects a new component to the top.
            int fallen = dfs(grid, r, c);

            // Exclude the brick we just restored.
            result[i] = fallen - 1;
        }

        return result;
    }
};