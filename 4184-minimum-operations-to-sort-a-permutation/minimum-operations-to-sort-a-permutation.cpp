class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();

        bool inc= true;
        bool dec= true;

        int start= nums[0];

        for(int i=0; i<n; i++){
            if(nums[i]!= (start+i)%n)
                inc= false;
            if(nums[i]!= (start-i+n)%n)
                dec= false;
        }
        int ans= INT_MAX;

        if(inc){
            int left= (n- start)%n;
            int right= start+2;

            ans= min(left, right);
        }

        if(dec){
            int s= (n-1- start+n)%n;

            int option1= 1+s;
            int option2= 1+n-s;

            ans= min(ans, min(option1, option2));
        }
        if(ans== INT_MAX)
            return -1;

        return ans;
    }
};