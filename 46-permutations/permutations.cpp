class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& curr, vector<int>& used){
        if(curr.size()== nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;

            curr.push_back(nums[i]);
            used[i]=1;

            solve(nums, curr, used);

            curr.pop_back();
            used[i]=0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();

        vector<int> used(nums.size(), 0);
        vector<int> curr;

        solve(nums, curr, used);

        return ans;
    }
};