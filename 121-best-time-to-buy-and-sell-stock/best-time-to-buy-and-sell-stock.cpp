class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minSoFar= INT_MAX;

        for(int i=0; i<prices.size(); i++){
            minSoFar= min(minSoFar, prices[i]);

            int profit= prices[i]- minSoFar;
            maxProfit= max(maxProfit, profit);
        }
        return maxProfit;
    }
};