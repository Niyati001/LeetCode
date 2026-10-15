
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Check whether any subset size is feasible
        bool possible = false;
        for (int k = 1; k < n; k++) {
            if (total * k % n == 0) {
                possible = true;
                break;
            }
        }
        if (!possible) return false;

        // dp[k] contains sums achievable with exactly k elements
        vector<unordered_set<int>> dp(n + 1);
        dp[0].insert(0);

        int processed = 0;

        for (int x : nums) {
            processed++;

            for (int k = processed; k >= 1; k--) {
                for (int s : dp[k - 1]) {
                    int newSum = s + x;

                    if (k<n && newSum * n == total * k)
                        return true;

                    dp[k].insert(newSum);
                }
            }
        }

        return false;
    }
};
