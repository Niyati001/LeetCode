class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);

            maxReach[left] = max(maxReach[left], right);
        }

        int taps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (i > farthest) return -1;

            farthest = max(farthest, maxReach[i]);

            if (i == currentEnd) {
                if (farthest == currentEnd) return -1;

                taps++;
                currentEnd = farthest;

                if (currentEnd >= n) return taps;
            }
        }

        return currentEnd >= n ? taps : -1;
    }
};
