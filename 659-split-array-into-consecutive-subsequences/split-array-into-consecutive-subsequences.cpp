class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> need;

        for(int x: nums)
            freq[x]++;
        
        for(int x: nums){
            if(freq[x]==0) continue;

            if(need[x]>0){
                freq[x]--;
                need[x]--;
                need[x+1]++;
            }

            else{
                if(freq[x+1]== 0 || freq[x+2]==0)
                    return false;
                
                freq[x]--;
                freq[x+1]--;
                freq[x+2]--;

                need[x+3]++;
            }
        }
        return true;
    }
};