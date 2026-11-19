class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n= nums.size();

        if(n== 1) return 0;

        int maxi= *max_element(nums.begin(), nums.end());

        vector<int> spf(maxi+ 1);

        for(int i= 2; i<= maxi; i++){
            if(spf[i]== 0){
                for(int j= i; j<= maxi; j+= i){
                    if(spf[j]== 0){
                        spf[j]= i;
                    }
                }
            }
        }

        vector<vector<int>> bucket(maxi + 1);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];

                bucket[p].push_back(i);

                while(x % p== 0) {
                    x/= p;
                }
            }
        }

        vector<int> dist(n, -1);

        queue<int> q;
        q.push(0);
        dist[0]= 0;

        while(!q.empty()) {
            int i= q.front();
            q.pop();

            if(i== n- 1) {
                return dist[i];
            }

            if(i+ 1< n && dist[i+ 1]== -1){
                dist[i+ 1]= dist[i]+ 1;
                q.push(i+ 1);
            }

            if(i- 1>= 0 && dist[i- 1]== -1){
                dist[i- 1]= dist[i]+ 1;
                q.push(i- 1);
            }

            int p = nums[i];

            if(p>= 2 && spf[p]== p){
                for(int j: bucket[p]){
                    if(dist[j]== -1){
                        dist[j]= dist[i]+ 1;
                        q.push(j);
                    }
                }

                bucket[p].clear();
            }
        }

        return -1;
    }
};
