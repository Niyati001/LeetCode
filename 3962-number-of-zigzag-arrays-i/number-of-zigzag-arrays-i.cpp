class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        int m = r - l + 1;

        vector<int> up(m + 1), down(m + 1);
        vector<int> newUp(m + 1), newDown(m + 1);
        vector<int> prefUp(m + 1), prefDown(m + 1);

        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        if (n == 2) {
            long long ans = 0;
            for (int v = 1; v <= m; v++) {
                ans = (ans + up[v] + down[v]) % MOD;
            }
            return (int)ans;
        }

        for (int len = 3; len <= n; len++) {

            prefUp[0] = prefDown[0] = 0;

            for (int i = 1; i <= m; i++) {
                prefUp[i] = (prefUp[i - 1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i - 1] + down[i]) % MOD;
            }

            int totalUp = prefUp[m];

            for (int v = 1; v <= m; v++) {

                newUp[v] = prefDown[v - 1];

                newDown[v] = totalUp - prefUp[v];
                if (newDown[v] < 0) newDown[v] += MOD;
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        long long ans = 0;

        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};