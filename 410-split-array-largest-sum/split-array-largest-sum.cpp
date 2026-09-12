class Solution {
public:
    bool possible(vector<int>& nums, int k, long long limit){
        int subarrays=1;
        long long sum=0;

        for(int x: nums){
            if(sum+x<= limit)
                sum+= x;
            else{
                subarrays++;
                sum=x;
            }
        }
        return subarrays<= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low= *max_element(nums.begin(), nums.end());
        long long high= accumulate(nums.begin(), nums.end(), 0LL);

        while(low< high){
            long long mid= low+ (high- low)/2;

            if(possible(nums, k, mid))
                high= mid;
            else
                low= mid+1;
        }
        return low;
    }
};