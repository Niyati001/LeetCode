class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans;
        pair<int, char> prev = {0, '#'};

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int count = curr.first;
            char ch = curr.second;

            ans += ch;
            count--;

            if(prev.first > 0) {
                pq.push(prev);
            }
            prev = {count, ch};
        }

        if(ans.size() != s.size())
            return "";

        return ans;
    }
};