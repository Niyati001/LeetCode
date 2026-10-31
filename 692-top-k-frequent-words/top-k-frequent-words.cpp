class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for(string word: words){
            freq[word]++;
        }

        vector<string> v;

        for(auto it: freq){
            v.push_back(it.first);
        }

        sort(v.begin(), v.end(), [&](string a, string b){
            if(freq[a]== freq[b]){
                return a< b;
            }

            return freq[a]> freq[b];
        });

        vector<string> ans;

        for(int i= 0; i< k; i++) {
            ans.push_back(v[i]);
        }

        return ans;
    }
};