class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for(int i=0; i<nums.size(); i++){
            int num= nums[i];
            int needed= target- num;

            if(m.count(needed)){
                return {m[needed], i};
            }
            m[num]=i;
        }
        return {};
    }
};