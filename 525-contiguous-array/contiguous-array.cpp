class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> first;

        first[0]= -1;

        int diff=0;
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1)
                diff++;

            if(nums[i]==0)
                diff--;

            if(first.count(diff)){
                ans= max(ans, i- first[diff]);
            }
        
            else{
                first[diff]= i;
            }
        }
        return ans;
    }
};