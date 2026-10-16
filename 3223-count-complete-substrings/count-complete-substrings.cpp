class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        int start = 0;

        while (start < n) {
            int end = start;

            // Find a maximal segment where adjacent letters differ by <= 2
            while (end + 1 < n &&
                   abs(word[end + 1] - word[end]) <= 2) {
                end++;
            }

            // Process this valid segment [start, end]
            for (int distinct = 1; distinct <= 26; distinct++) {
                int len = distinct * k;
                if (len > end - start + 1) break;

                vector<int> freq(26, 0);
                int good = 0;

                for (int i = start; i <= end; i++) {
                    int c = word[i] - 'a';
                    freq[c]++;

                    if (freq[c] == k) good++;
                    else if (freq[c] == k + 1) good--;

                    // Maintain a window of length len
                    if (i - start + 1 > len) {
                        int out = word[i - len] - 'a';

                        if (freq[out] == k) good--;
                        else if (freq[out] == k + 1) good++;

                        freq[out]--;
                    }

                    // Every present character must occur exactly k times
                    if (i - start + 1 >= len && good == distinct) {
                        int totalDistinct = 0;
                        bool valid = true;

                        for (int f : freq) {
                            if (f > 0) {
                                totalDistinct++;
                                if (f != k) {
                                    valid = false;
                                    break;
                                }
                            }
                        }

                        if (valid && totalDistinct == distinct) {
                            ans++;
                        }
                    }
                }
            }

            start = end + 1;
        }

        return ans;
    }
};
