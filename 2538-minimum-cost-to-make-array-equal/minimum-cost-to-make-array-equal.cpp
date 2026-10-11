class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n= nums.size();
        vector<pair<int, int>> arr;

        long long totalWeight=0;

        for(int i=0; i<n; i++){
            arr.push_back({nums[i], cost[i]});
            totalWeight+= cost[i];
        }
        sort(arr.begin(), arr.end());

        long long prefix=0;
        int target= arr[0].first;

        for(auto p: arr){
            prefix+= p.second;

            if(prefix*2>= totalWeight){
                target= p.first;
                break;
            }
        }
        long long ans=0;

        for(int i=0; i<n; i++){
            ans+= 1LL* abs(nums[i]-target)* cost[i];
        }
        return ans;
    }
};