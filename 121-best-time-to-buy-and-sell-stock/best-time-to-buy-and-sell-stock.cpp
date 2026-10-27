class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit= 0;
        int lowest= prices[0];

        for(int i=1; i<prices.size(); i++){
            int profit= prices[i]- lowest;

            if(prices[i]< lowest)
                lowest= prices[i];
            
            maxProfit= max(profit, maxProfit);
        }
        return maxProfit;
    }
};