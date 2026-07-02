class Solution {
public:
    bool solve(int i, string &s, unordered_set<string> &dict, vector<int>& dp){
        if(i== s.size()) return true;
        if(dp[i]!= -1) return dp[i];

        string curr= "";
        for(int j=i; j< s.size(); j++){
            curr+=s[j];

            if(dict.count(curr)){
                if(solve(j+1, s, dict, dp)){
                    return dp[i]= true;
                }
            }
        }
        return dp[i]= false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(0, s, dict, dp);
    }
};