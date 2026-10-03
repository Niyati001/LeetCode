class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0;

        int currMax=0, maxSum= nums[0];
        int currMin=0, minSum= nums[0];

        for(int x: nums){
            currMax= max(x, currMax+ x);
            maxSum= max(maxSum, currMax);

            currMin= min(x, currMin+x);
            minSum= min(minSum, currMin);

            totalSum+= x;
        }

        if(maxSum<0)
            return maxSum;

        return max(maxSum, totalSum- minSum);
    }
};