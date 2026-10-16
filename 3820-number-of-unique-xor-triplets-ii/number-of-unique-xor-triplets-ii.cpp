
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());

        vector<int> present(M + 1, 0);
        vector<int> vals;

        for (int x : nums) {
            if (!present[x]) {
                present[x] = 1;
                vals.push_back(x);
            }
        }

        // XOR of every possible pair of values
        vector<int> pairXor(2048, 0);

        for (int x : vals) {
            for (int y : vals) {
                pairXor[x ^ y] = 1;
            }
        }

        // XOR each reachable pair value with each array value
        vector<int> tripletXor(2048, 0);

        for (int x = 0; x < 2048; x++) {
            if (pairXor[x]) {
                for (int y : vals) {
                    tripletXor[x ^ y] = 1;
                }
            }
        }

        int ans = 0;
        for (int x = 0; x < 2048; x++) {
            ans += tripletXor[x];
        }

        return ans;
    }
};
