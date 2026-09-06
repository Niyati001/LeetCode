class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;  // maximum till i-2
        int prev1 = 0;  // maximum till i-1

        for(int money : nums) {
            int curr = max(prev1, prev2 + money);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};