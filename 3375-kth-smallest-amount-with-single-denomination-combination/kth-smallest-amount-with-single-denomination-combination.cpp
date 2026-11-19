class Solution {
public:
    long long countValid(long long x, vector<int>& coins){
        int n= coins.size();
        long long ans=0;

        int total= 1<<n;

        vector<long long> lcm(total, 0);
        lcm[0]=1;

        for(int mask=1; mask<total; mask++){
            int bit= __builtin_ctz(mask);
            int prev= mask & (mask-1);

            long long a= lcm[prev];
            long long b= coins[bit];

            long long g= gcd(a, b);

            if(a> x/ (b/g)){
                lcm[mask]= x+1;
            }
            else{
                lcm[mask]= a*(b/g);
            }

            if(lcm[mask]> x)
                continue;

            int bits= __builtin_popcount(mask);
            long long ways= x/ lcm[mask];

            if(bits%2==1)
                ans+= ways;

            else
                ans-= ways;
        }
        return ans;
    }
    
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low=1;
        int minCoin= *min_element(coins.begin(), coins.end());
        long long high= (long long)k* minCoin;

        while(low<high){
            long long mid= low+ (high-low)/2;

            if(countValid(mid, coins)>=k)
                high= mid;
            else
                low= mid+1;
        }
        return low;
    }
};