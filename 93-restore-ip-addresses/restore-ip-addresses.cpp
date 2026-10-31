class Solution {
public:
    vector<string> ans;

    void solve(string& s, int idx, int parts, string current) {
        if (parts == 4) {
            if (idx == s.size()) {
                current.pop_back(); 
                ans.push_back(current);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (idx + len > s.size())
                break;

            string segment = s.substr(idx, len);

            if (segment.size() > 1 && segment[0] == '0')
                continue;

            int num = stoi(segment);

            if (num > 255)
                continue;

            solve(s, idx + len, parts + 1, current + segment + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        if (s.size() < 4 || s.size() > 12)
            return ans;

        solve(s, 0, 0, "");

        return ans;
    }
};