class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        for (string word : words)
            freq[word]++;

        vector<string> arr;

        for (auto x : freq)
            arr.push_back(x.first);

        sort(arr.begin(), arr.end(), [&](string a, string b) {
            if (freq[a] != freq[b])
                return freq[a] > freq[b];

            return a < b;
        });

        arr.resize(k);

        return arr;
    }
};