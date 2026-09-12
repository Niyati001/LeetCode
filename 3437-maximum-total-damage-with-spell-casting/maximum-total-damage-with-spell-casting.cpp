class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> freq;

        for (int x : power)
            freq[x]++;

        vector<pair<int, long long>> a(freq.begin(), freq.end());

        int n = a.size();

        vector<long long> dp(n, 0);

        for (int i = 0; i < n; i++) {

            // Don't take current damage
            dp[i] = (i > 0 ? dp[i - 1] : 0);

            // Find first index whose damage >= current - 2
            // We need values <= current - 3.
            int low = 0, high = i - 1;
            int j = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (a[mid].first <= a[i].first - 3) {
                    j = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            // Take all spells with this damage
            long long take = 1LL * a[i].first * a[i].second;

            if (j >= 0)
                take += dp[j];

            dp[i] = max(dp[i], take);
        }

        return dp[n - 1];
    }
};