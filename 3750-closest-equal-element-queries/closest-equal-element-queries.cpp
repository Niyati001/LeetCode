class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Store indices for each value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            vector<int>& indices = mp[nums[q]];

            // Only one occurrence
            if (indices.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            // Find position of q in sorted indices list
            int pos = lower_bound(indices.begin(), indices.end(), q) - indices.begin();

            int m = indices.size();

            int prevIdx = indices[(pos - 1 + m) % m];
            int nextIdx = indices[(pos + 1) % m];

            int d1 = abs(q - prevIdx);
            d1 = min(d1, n - d1);

            int d2 = abs(q - nextIdx);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};