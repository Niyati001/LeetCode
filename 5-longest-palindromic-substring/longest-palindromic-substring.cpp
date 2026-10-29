class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 0;

        for (int i = 0; i < n; i++){
            // Case 1: Odd-length palindrome
            int left = i, right = i;

            while (left >= 0 && right < n && s[left] == s[right]){
                left--;
                right++;
            }

            int len = right - left - 1;

            if (len > maxLen){
                maxLen = len;
                start = left + 1;
            }

            // Case 2: Even-length palindrome
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]){
                left--;
                right++;
            }

            len = right - left - 1;

            if (len > maxLen){
                maxLen = len;
                start = left + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};
