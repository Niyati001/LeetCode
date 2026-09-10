class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int totalEven=0;
        int totalOdd=0;

        for(int i=0; i< nums.size(); i++){
            if(i%2==0)
                totalEven+= nums[i];
            else
                totalOdd+= nums[i];
        }
        int leftEven=0;
        int leftOdd=0;
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            int rightEven= totalEven- leftEven;
            int rightOdd= totalOdd- leftOdd;

            if(i%2==0)  
                rightEven-= nums[i];
            else
                rightOdd-= nums[i];

            int newEven= leftEven+ rightOdd;
            int newOdd= leftOdd+ rightEven;

            if(newEven== newOdd) ans++;
            
            // add current element to the right side
            if(i%2==0) 
                leftEven+= nums[i];
            else
                leftOdd+= nums[i];
        }
        return ans;
    }
};