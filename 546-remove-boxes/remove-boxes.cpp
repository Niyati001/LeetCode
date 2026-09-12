class Solution {
public:
    int dp[100][100][100];

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r)
            return 0;

        // Merge consecutive boxes having the same color
        while (l + 1 <= r && boxes[l] == boxes[l + 1]) {
            l++;
            k++;
        }

        // IMPORTANT:
        // Memoize using the compressed (l, r, k) state.
        if (dp[l][r][k] != -1)
            return dp[l][r][k];

        // Option 1:
        // Remove the current group now.
        int ans = (k + 1) * (k + 1)
                + solve(boxes, l + 1, r, 0);

        // Option 2:
        // Keep current group and merge it with
        // another box of the same color.
        for (int i = l + 1; i <= r; i++) {
            if (boxes[i] == boxes[l]) {

                int removeMiddle = solve(boxes, l + 1, i - 1, 0);

                int merge = solve(boxes, i, r, k + 1);

                ans = max(ans, removeMiddle + merge);
            }
        }

        return dp[l][r][k] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));

        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};