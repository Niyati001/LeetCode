class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans= strs[0];

        for(int i=0; i< ans.size(); i++){
            char ch= ans[i];

            for(int j=1; j<strs.size(); j++){
                if(i>= strs[j].size() || strs[j][i]!= ch){
                    return ans.substr(0, i);
                }
            }
        }
        return ans;
    }
};