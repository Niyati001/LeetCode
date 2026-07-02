class Solution {
public:
    vector<string> mapping= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(int idx, string &digits, string &curr, vector<string>& ans){
        if(idx== digits.size()){
            ans.push_back(curr);
            return;
        }

        int digit= digits[idx]- '0';
        string letters= mapping[digit];

        for(char ch: letters){
            curr.push_back(ch);
            solve(idx+1, digits, curr, ans);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()== 0) return ans;

        string curr= "";
        solve(0, digits, curr, ans);
        return ans;
    }
};