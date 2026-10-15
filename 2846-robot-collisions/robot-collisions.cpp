
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st;

        for (int i : idx) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && healths[i] > 0) {
                    int j = st.top();

                    if (healths[j] < healths[i]) {
                        st.pop();
                        healths[i]--;
                        healths[j] = 0;
                    } else if (healths[j] > healths[i]) {
                        healths[j]--;
                        healths[i] = 0;
                    } else {
                        st.pop();
                        healths[j] = 0;
                        healths[i] = 0;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};
