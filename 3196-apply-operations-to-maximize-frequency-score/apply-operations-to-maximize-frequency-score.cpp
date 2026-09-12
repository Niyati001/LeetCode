class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int left = 0;
        int ans = 1;

        for (int right = 0; right < n; right++) {

            while (left <= right) {
                int mid = left + (right - left) / 2;

                // Cost to make [left...mid] equal to nums[mid]
                long long leftCost =
                    1LL * nums[mid] * (mid - left)
                    - (prefix[mid] - prefix[left]);

                // Cost to make [mid...right] equal to nums[mid]
                long long rightCost =
                    (prefix[right + 1] - prefix[mid + 1])
                    - 1LL * nums[mid] * (right - mid);

                long long cost = leftCost + rightCost;

                if (cost <= k)
                    break;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};