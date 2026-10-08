class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);
        string st;

        for(char c: s)
            freq[c- 'a']++;

        for(char ch: s){
            freq[ch- 'a']--;

            if(used[ch- 'a'])
                continue;

            while(!st.empty() && st.back()> ch && freq[st.back()- 'a']> 0){
                used[st.back()- 'a']= false;
                st.pop_back();
            }

            st.push_back(ch);
            used[ch- 'a']= true;
        }
        return st;
    }
};