class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minDeque;
        deque<int> maxDeque;

        int left=0;
        int ans=0;

        for(int right=0; right< nums.size(); right++){
            // maintain increasing deque for minimum
            while(!minDeque.empty() && nums[minDeque.back()]> nums[right])
                minDeque.pop_back();
            
            minDeque.push_back(right);

            //decreasing deque for maximum
            while(!maxDeque.empty() && nums[maxDeque.back()]< nums[right])
                maxDeque.pop_back();
            maxDeque.push_back(right);

            //window is invalid
            while(nums[maxDeque.front()]- nums[minDeque.front()]> limit){
                if(minDeque.front()== left)
                    minDeque.pop_front();
                
                if(maxDeque.front()== left)
                    maxDeque.pop_front();
                
                left++;
            }
            ans= max(ans, right-left+1);
        }
        return ans;
    }
};