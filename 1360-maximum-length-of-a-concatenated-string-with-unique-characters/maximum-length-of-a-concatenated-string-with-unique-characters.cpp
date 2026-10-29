class Solution {
public:
    int ans = 0;

    void backtrack(vector<string>& arr, int idx, int mask, int len) {
        ans = max(ans, len);

        if (idx == arr.size())
            return;

        // Choice 1: Skip the current string
        backtrack(arr, idx + 1, mask, len);

        int currMask = 0;
        bool valid = true;

        for (char c : arr[idx]) {
            int bit = 1 << (c - 'a');

            if (currMask & bit) {
                valid = false;
                break;
            }
            currMask |= bit;
        }

        // Choice 2: Take the string if valid
        if (valid && !(mask & currMask)) {backtrack(arr, idx + 1, mask | currMask, len + arr[idx].size());
        }
    }

    int maxLength(vector<string>& arr) {
        ans = 0;
        backtrack(arr, 0, 0, 0);
        return ans;
    }
};
