class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n= stones.size();

        unordered_map<int, int> index;
        for(int i=0; i<n; i++)
            index[stones[i]]= i;

        vector<unordered_set<int>> dp(n);

        dp[0].insert(0);

        for(int i=0; i<n; i++){
            for(int jump: dp[i]){

                for(int nextJump= jump-1; nextJump<= jump+1; nextJump++){
                    if(nextJump<=0) continue;

                    int nextPos= stones[i]+ nextJump;

                    if(index.count(nextPos)){
                        int nextIndex= index[nextPos];
                        dp[nextIndex].insert(nextJump);
                    }
                }
            }
        }
        return !dp[n-1].empty();
    }
};