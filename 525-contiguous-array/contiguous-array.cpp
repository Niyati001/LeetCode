class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        mp[0]= -1;

        int diff=0;
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]== 1)
                diff++;
            else
                diff--;

            if(mp.count(diff))
                ans= max(ans, i- mp[diff]);
            
            else
                mp[diff]= i;
        }
        return ans;
    }
};