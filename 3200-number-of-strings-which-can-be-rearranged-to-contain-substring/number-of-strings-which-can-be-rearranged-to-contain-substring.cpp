
class Solution {
public:
    int stringCount(int n) {
        const long long MOD = 1'000'000'007;

        if (n < 4) return 0;

        // dp[e][l][t]:
        // e = number of e's, capped at 2
        // l = whether at least one l has appeared
        // t = whether at least one t has appeared
        long long dp[3][2][2] = {};
        dp[0][0][0] = 1;

        for (int i = 0; i < n; i++) {
            long long ndp[3][2][2] = {};

            for (int e = 0; e <= 2; e++) {
                for (int l = 0; l <= 1; l++) {
                    for (int t = 0; t <= 1; t++) {
                        long long cur = dp[e][l][t];

                        // Any of the 23 irrelevant letters
                        ndp[e][l][t] =
                            (ndp[e][l][t] + cur * 23) % MOD;

                        // Add 'e'
                        int ne = min(2, e + 1);
                        ndp[ne][l][t] = (ndp[ne][l][t] + cur) % MOD;

                        // Add 'l'
                        ndp[e][1][t] = (ndp[e][1][t] + cur) % MOD;

                        // Add 't'
                        ndp[e][l][1] = (ndp[e][l][1] + cur) % MOD;
                    }
                }
            }

            memcpy(dp, ndp, sizeof(dp));
        }

        return dp[2][1][1];
    }
};
