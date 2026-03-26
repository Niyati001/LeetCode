class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);

        for(char c: t){
            hash[c]++;
        }
        int l=0; int r=0;
        int count= t.size();
        int minLen= INT_MAX;
        int start=0;

        while(r< s.size()){
            if(hash[s[r]]>0){
                count--;
            }
            hash[s[r]]--;

            while(count==0){
                if(r-l+1< minLen){
                    minLen= r-l+1;
                    start=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count++;
                }
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};