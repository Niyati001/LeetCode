class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int left=0;
        int cnt=0;
        int ans=0;

        for(int right=0; right< nums.size(); right++){
            if(nums[right]%2== 1)
                k--;

            while(k<0){
                if(nums[left]%2==1)
                    k++;
                left++;
            }
            ans+= right-left+1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return (atmost(nums, k)- atmost(nums, k-1));
    }
};