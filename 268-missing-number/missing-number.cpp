class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();

        int sum= n*(n+1)/2;
        int start=0;

        for(int i=0; i<n; i++){
            start= start+nums[i];
        }
        return sum-start;
    }
};