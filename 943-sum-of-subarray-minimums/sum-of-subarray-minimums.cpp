class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        long long ans=0;

        const long long MOD= 1e9+ 7;

        stack<int> st;

        for(int i=0; i<=n; i++){
            int curr= (i==n)? 0: arr[i];
            while(!st.empty() && arr[st.top()]> curr){
                int mid= st.top();
                st.pop();

                int left;

                if(st.empty())
                    left= mid+1;

                else
                    left= mid- st.top();

                int right= i- mid;

                ans= (ans+ 1LL*arr[mid]*left*right)% MOD;
            }
            st.push(i);
        }
        return ans;
    }
};