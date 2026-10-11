class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0]=1;

        int oddCount=0, ans=0;

        for(int x: nums){
            if(x%2!=0)
                oddCount++;

            ans+= freq[oddCount-k];
            freq[oddCount]++;
        }
        return ans;
    }
};