class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);

        dp[0]=0;

        for(int x=1; x<= amount; x++){
            for(int coin: coins){
                if(coin<= x){
                    dp[x]= min(dp[x], dp[x-coin]+1);
                }
            }
        }
        if(dp[amount]== amount+1)
            return -1;

        return dp[amount];
    }
};