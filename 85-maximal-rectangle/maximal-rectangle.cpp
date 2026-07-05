class Solution {
public:
    int largestHistogram(vector<int>& heights){
        stack<int> st;
        int n= heights.size();
        int maxArea= 0;

        for(int i=0; i<=n; i++){
            int h= (i==n? 0: heights[i]);
            while(!st.empty() && h< heights[st.top()]){
                int height= heights[st.top()];
                st.pop();

                int width;

                if(st.empty())
                    width=i;
                else{
                    width= i- st.top()-1;
                }
                maxArea= max(maxArea, height* width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;

        int n= matrix.size();
        int m= matrix[0].size();

        vector<int> height(m, 0);
        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]== '1')
                    height[j]+= 1;
                else
                    height[j]=0;
            }
            ans= max(ans, largestHistogram(height));
        }
        return ans;
    }
};