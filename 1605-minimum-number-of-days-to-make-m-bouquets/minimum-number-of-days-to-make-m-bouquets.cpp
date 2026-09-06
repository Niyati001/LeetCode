class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int days){
        int flowers=0;
        int bouquets=0;

        for(int i=0; i< bloomDay.size(); i++){
            if(bloomDay[i]<= days){
                flowers++;

                if(flowers== k){
                    bouquets++;
                    flowers=0;
                }
            }

            else{
                flowers=0;
            }
        }
        return bouquets>= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m* k> bloomDay.size())
            return -1;

        int low=1;
        int high= *max_element(bloomDay.begin(), bloomDay.end());

        while(low<= high){
            int mid= low+ (high- low)/2;

            if(possible(bloomDay, m, k, mid))
                high= mid-1;
            else
                low= mid+1;
        }
        return low;
    }
};