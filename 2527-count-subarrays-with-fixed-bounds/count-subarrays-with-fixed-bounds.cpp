class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        long long ans = 0;

        int lastMin = -1;
        int lastMax = -1;
        int bad = -1;

        for (int i = 0; i < nums.size(); i++) {

            // Invalid value
            if (nums[i] < minK || nums[i] > maxK)
                bad = i;

            // Found minK
            if (nums[i] == minK)
                lastMin = i;

            // Found maxK
            if (nums[i] == maxK)
                lastMax = i;

            int validEnd = min(lastMin, lastMax);

            if (validEnd > bad)
                ans += validEnd - bad;
        }

        return ans;
    }
};