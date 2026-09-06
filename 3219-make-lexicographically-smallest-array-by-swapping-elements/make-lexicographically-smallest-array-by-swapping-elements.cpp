class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n= nums.size();

        vector<pair<int, int>> arr;

        // {value, original index}
        for(int i=0; i<n; i++){
            arr.push_back({nums[i], i});
        }

        //sort by value
        sort(arr.begin(), arr.end());

        int start=0;
        
        while(start<n){
            int end= start;

            //find one connected group
            while(end+1< n && arr[end+1].first- arr[end].first<= limit){
                end++;
            }

            //get original indices of group
            vector<int> indices;

            for(int i= start; i<= end; i++){
                indices.push_back(arr[i].second);
            }

            //smallest index should get smallest value
            sort(indices.begin(), indices.end());

            for(int i=0; i<indices.size(); i++){
                nums[indices[i]]= arr[start+i].first;
            }
            start= end+1;
        }
        return nums;
    }
};