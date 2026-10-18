
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> haveBox(n, false);
        vector<bool> used(n, false);

        queue<int> q;

        for (int box : initialBoxes) {
            haveBox[box] = true;

            if (status[box] == 1) {
                q.push(box);
                used[box] = true;
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            ans += candies[box];

            for (int key : keys[box]) {
                status[key] = 1;

                if (haveBox[key] && !used[key]) {
                    q.push(key);
                    used[key] = true;
                }
            }

            for (int nextBox : containedBoxes[box]) {
                haveBox[nextBox] = true;

                if (status[nextBox] == 1 && !used[nextBox]) {
                    q.push(nextBox);
                    used[nextBox] = true;
                }
            }
        }

        return ans;
    }
};
