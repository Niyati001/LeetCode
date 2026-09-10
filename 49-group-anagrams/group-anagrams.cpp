class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string s: strs){
            vector<int> count(26, 0);

            for(char c: s)
                count[c- 'a']++;
            
            string key;

            for(int x: count)
                key+= to_string(x)+ "#";

            mp[key].push_back(s);
        }
        vector<vector<string>> ans;

        for(auto &it: mp)
            ans.push_back(it.second);

        return ans;
    }
};