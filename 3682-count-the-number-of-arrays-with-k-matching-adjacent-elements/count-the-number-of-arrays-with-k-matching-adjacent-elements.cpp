class Solution {
public:
    long long mod= 1e9+7;

    long long power(long long a, long long b){
        long long ans=1;

        while(b>0){
            if(b & 1)
                ans= ans*a% mod;
            
            a= a*a% mod;
            b/=2;
        }
        return ans;
    }

    int countGoodArrays(int n, int m, int k) {
        if(k> n-1) return 0;

        // C(n-1, k)
        long long comb=1;

        for(int i=1; i<= k; i++){
            comb= comb*(n-i)% mod;
            comb= comb* power(i, mod-2)% mod;
        }

        long long ans= comb;

        //first element-> m choices
        ans= ans*m% mod;

        //diff positions-> m-1 choices
        ans= ans* power(m-1, n-1-k)% mod;

        return ans;
    }
};