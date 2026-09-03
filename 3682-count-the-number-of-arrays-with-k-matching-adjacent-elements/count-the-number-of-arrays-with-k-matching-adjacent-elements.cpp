class Solution {
public:
    long long mod= 1e9+7;

    long long power(long long a, long long b){
        long long ans=1;

        while(b>0){
            if(b% 2)
                ans= ans*a% mod;
            
            a= a*a% mod;
            b/=2;
        }
        return ans;
    }

    int countGoodArrays(int n, int m, int k) {
        if(k> n-1) return 0;

        vector<long long> fact(n);
        fact[0]=1;

        for(int i=1; i<n; i++){
            fact[i]= fact[i-1]*i% mod;
        }

        long long comb= fact[n-1];

        comb= comb* power(fact[k], mod-2)% mod;
        comb= comb* power(fact[n-1-k], mod-2)% mod;

        long long ans= m;

        ans= ans* comb% mod;
        ans= ans* power(m-1, n-1-k)% mod;

        return ans;
    }
};