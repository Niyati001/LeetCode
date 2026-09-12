class Solution {
public:
    int n;
    string ring, key;
    vector<vector<int>> dp;

    int solve(int i, int pos){
        if(i== key.size())
            return 0;
        
        if(dp[i][pos]!= -1)
            return dp[i][pos];

        int ans= INT_MAX;

        // try every position where key[i] occurs
        for(int p=0; p<n; p++){
            if(ring[p]!= key[i])
                continue;
            
            int diff= abs(pos-p);
            int rotate= min(diff, n- diff);

            int cost= rotate+ 1+ solve(i+1, p);
            
            ans= min(ans, cost);
        }
        return dp[i][pos]= ans;
    }

    int findRotateSteps(string ring, string key) {
        this-> ring= ring;
        this-> key= key;

        n= ring.size();

        dp.assign(key.size(), vector<int>(n, -1));

        return solve(0,0);
    }
};