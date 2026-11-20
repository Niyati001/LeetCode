class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n= nums.size();

        long long operations=0;
        long long limit= nums[n-1];

        for(int i= n-1; i>=0; i--){
            if(nums[i]<= limit)
                limit= nums[i];
            else{
                long long parts= (nums[i]+ limit-1)/ limit;
                operations+= parts-1;
                limit= nums[i]/ parts;
            }
        }
        return operations;
    }
};