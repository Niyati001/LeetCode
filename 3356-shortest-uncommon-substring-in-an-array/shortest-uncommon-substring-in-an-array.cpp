
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr){
        int n = arr.size();
        unordered_map<string, int> freq;

        for (const string& s : arr){
            unordered_set<string> seen;

            for (int len = 1; len <= s.size(); len++){
                for (int start = 0; start + len <= s.size(); start++){
                    seen.insert(s.substr(start, len));
                }
            }

            for (const string& sub : seen){
                freq[sub]++;
            }
        }

        vector<string> answer(n);

        for (int i = 0; i < n; i++){
            const string& s = arr[i];

            for (int len = 1; len <= s.size(); len++){
                string best = "";

                for (int start = 0; start + len <= s.size(); start++){
                    string sub = s.substr(start, len);

                    if (freq[sub] == 1) {
                        if (best.empty() || sub < best) {
                            best = sub;
                        }
                    }
                }
                if (!best.empty()) {
                    answer[i] = best;
                    break;
                }
            }
        }

        return answer;
    }
};
