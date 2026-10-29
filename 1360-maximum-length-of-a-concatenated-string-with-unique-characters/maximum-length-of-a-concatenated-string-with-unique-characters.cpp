class Solution {
public:
    int ans = 0;

    void solve(vector<string>& arr, int idx, string current) {
        bool seen[26] = {};

        for (char c : current) {
            if (seen[c - 'a'])
                return;

            seen[c - 'a'] = true;
        }

        ans = max(ans, (int)current.size());

        if (idx == arr.size())
            return;

        // Choice 1: Skip current string
        solve(arr, idx + 1, current);

        // Choice 2: Take current string
        solve(arr, idx + 1, current + arr[idx]);
    }

    int maxLength(vector<string>& arr) {
        ans = 0;
        solve(arr, 0, "");
        return ans;
    }
};
