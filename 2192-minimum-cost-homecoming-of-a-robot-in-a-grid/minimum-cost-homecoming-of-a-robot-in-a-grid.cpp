class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,vector<int>& rowCosts, vector<int>& colCosts) {

        int sr = startPos[0];
        int sc = startPos[1];

        int hr = homePos[0];
        int hc = homePos[1];

        int ans = 0;

        if (sr < hr) {
            for (int r = sr + 1; r <= hr; r++) {
                ans += rowCosts[r];
            }
        }
        else {
            for (int r = sr - 1; r >= hr; r--) {
                ans += rowCosts[r];
            }
        }

        if(sc < hc) {
            for (int c = sc + 1; c <= hc; c++) {
                ans += colCosts[c];
            }
        }
        else{
            for (int c = sc - 1; c >= hc; c--) {
                ans += colCosts[c];
            }
        }

        return ans;
    }
};
