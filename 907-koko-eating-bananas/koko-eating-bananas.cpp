class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int k){
        long long hours=0;

        for(int pile: piles){
            hours+= (pile+k-1)/k;
        }
        return hours<= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right= *max_element(piles.begin(), piles.end());

        int ans= right;

        while(left<= right){
            int mid= left+ (right- left)/2;

            if(canFinish(piles, h, mid)){
                ans= mid;
                right= mid-1;
            }
            else{
                left= mid+1;
            }
        }
        return ans;
    }
};