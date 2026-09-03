class Solution {
public:
    vector<int> KMP(string s, string p) {
        string x = p + "#" + s;
        int n = x.size();

        vector<int> lps(n, 0);
        vector<int> pos;

        for(int i = 1; i < n; i++) {
            int j = lps[i - 1];

            while(j > 0 && x[i] != x[j])
                j = lps[j - 1];

            if(x[i] == x[j])
                j++;

            lps[i] = j;

            if(lps[i] == p.size())
                pos.push_back(i - 2 * p.size());
        }

        return pos;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> A= KMP(s, a);
        vector<int> B= KMP(s, b);
        
        vector<int> ans;

        int j = 0;

        for(int i : A) {
            while(j < B.size() && B[j] < i-k)
                j++;

            if(j < B.size() && B[j] <= i+k)
                ans.push_back(i);
        }

        return ans;
    }
};