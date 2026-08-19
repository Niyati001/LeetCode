class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int x: asteroids){
            bool alive= true;
            while(alive && x<0 && !st.empty() && st.top()> 0){
                if(st.top()< -x){
                    st.pop();
                }
                else if(st.top()== -x){
                    st.pop();
                    alive= false;
                }
                else{
                    alive= false;
                }
            }
            if(alive) st.push(x);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};