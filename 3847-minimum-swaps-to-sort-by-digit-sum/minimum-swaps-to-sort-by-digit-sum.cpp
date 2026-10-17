class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> sorted;
        for (int i = 0; i < n; i++) {
            sorted.push_back({nums[i], i});
        }

        // Sort by digit sum, then by number
        sort(sorted.begin(), sorted.end(), [&](auto& a, auto& b) {
            int sumA = digitSum(a.first);
            int sumB = digitSum(b.first);

            if (sumA != sumB) return sumA < sumB;
            return a.first < b.first;
        });

        // Find where each original index should go
        vector<int> target(n);
        for (int i = 0; i < n; i++) {
            target[sorted[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || target[i] == i) continue;

            int cycleLength = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = target[j];
                cycleLength++;
            }

            swaps += cycleLength - 1;
        }

        return swaps;
    }
};
