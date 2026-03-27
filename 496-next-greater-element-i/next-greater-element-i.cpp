class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> arr;

        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && st.top()< nums2[i]){
                mp[st.top()]= nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
            while(!st.empty()){
                mp[st.top()]= -1;
                st.pop();
            }
            for(int i: nums1){
                arr.push_back(mp[i]);
            }
        return arr;
    }
};