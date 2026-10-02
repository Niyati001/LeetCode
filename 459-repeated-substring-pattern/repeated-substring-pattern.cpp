class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n= s.size();

        for(int len=1; len<= n/2; len++){
            if(n%len!=0)  continue;

            string sub= s.substr(0, len);
            string formed= "";

            for(int i=0; i<n/ len; i++){
                formed+= sub;
            }

            if(formed== s)
                return true;
        }
        return false;
    }
};