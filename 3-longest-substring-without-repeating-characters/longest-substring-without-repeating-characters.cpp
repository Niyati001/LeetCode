class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0; int r=0; int len;
        int maxLen=0;
        vector<int> hash(256,-1);
        int n= s.size();
        
        while(r<n){
            if(hash[s[r]]!= -1 && hash[s[r]]>= l){
                    l= hash[s[r]]+1;
                }
            len= r-l+1;
            maxLen= max(len, maxLen);
            hash[s[r]]= r;
            r++;
        }
        return maxLen;
    }
};