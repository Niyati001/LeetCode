class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());

        int ans=0;

        for(int house: houses){
            // first heater>= house
            int idx= lower_bound(heaters.begin(), heaters.end(), house)- heaters.begin();

            int left= INT_MAX;
            int right= INT_MAX;

            //heater on the left
            if(idx>0)
                left= house- heaters[idx-1];
            
            //heater on the right
            if(idx< heaters.size())
                right= heaters[idx]- house;

            // closest heater to this house
            int closest= min(left, right);

            ans= max(ans, closest);
        }
        return ans;
    }
};