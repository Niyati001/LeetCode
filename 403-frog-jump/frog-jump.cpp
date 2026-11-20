class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n= stones.size();

        if(n==1) return true;

        if(stones[1]!=1) return false;

        unordered_map<int, int> index;

        for(int i=0; i<n; i++){
            index[stones[i]]= i;
        }

        vector<unordered_set<int>> dp(n);

        dp[0].insert(0);

        for(int i=0; i<n; i++){
            for(int k: dp[i]){
                for(int jump= k-1; jump<= k+1; jump++){
                    if(jump<=0) continue;
                    int nextPos= stones[i]+ jump;

                    if(index.find(nextPos)!= index.end()){
                        int j= index[nextPos];
                        dp[j].insert(jump);
                    }
                }
            }
        }
        return !dp[n-1].empty();
    }
};