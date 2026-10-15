class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> points(maxVal + 1, 0);

        for (int x : nums) {
            points[x] += x;
        }

        int prev2 = 0;
        int prev1 = 0;

        for (int x = 1; x <= maxVal; x++) {
            int curr = max(prev1, prev2 + points[x]);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
