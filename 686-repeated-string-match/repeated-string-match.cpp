class Solution {
public:
        const int base=256;
        const int mod= 1e9+7;
        
        bool rabinKarp(string text, string pattern){
            int n= text.size();
            int m= pattern.size();

            if(m>n) return false;

            long long txtHash=0, patHash=0, power=1;

            // compute base^(m-1)
            for(int i=0; i<m-1; i++){
                power= (power*base)%mod;
            }

            //initial hash
            for(int i=0; i<m; i++){
                patHash= (patHash*base + pattern[i])%mod;
                txtHash= (txtHash*base + text[i])%mod;
            }
            for(int i=0; i<=n-m; i++){
                if(patHash== txtHash){
                    if(text.substr(i,m)== pattern)
                        return true;
                }
                if(i< n-m){
                    txtHash= (txtHash- text[i]* power% mod + mod)% mod;
                    txtHash= (txtHash*base + text[i+m])% mod;
                }
            }
            return false;
        }


        int repeatedStringMatch(string a, string b) {
            string temp=a;
            int count=1;

            //grow until >=b
            while(temp.size()< b.size()){
                temp+=a;
                count++;
            }

            if(rabinKarp(temp, b)) return count;

            temp+=a;
            count++;

            if(rabinKarp(temp,b)) return count;

            return -1;
    }
};