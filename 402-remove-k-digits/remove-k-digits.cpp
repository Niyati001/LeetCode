class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for(char digit: num){
            while(!st.empty() && k>0 && st.back()> digit){
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }
        
        // if k is still left then remove digits from back
        while(k>0){
            st.pop_back();
            k--;
        }

        // remove leading zeros
        int i=0;
        while(i< st.size() && st[i]== '0')
            i++;
        string ans= st.substr(i);

        if(ans.empty()) return "0";
        
        return ans;
    }
};