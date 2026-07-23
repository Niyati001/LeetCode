class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int windowSize= n-k;
        int total=0;

        for(int x: cardPoints) total+= x;

        if(windowSize==0) return total;

        int curr=0;
        for(int i=0; i< windowSize; i++)
            curr+= cardPoints[i];

        int minSum= curr;

        for(int i= windowSize; i< n; i++){
            curr+= cardPoints[i];
            curr-= cardPoints[i- windowSize];

            minSum= min(minSum, curr);
        }
        return total- minSum;
    }
};