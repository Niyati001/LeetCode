class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n= words.size();
        int ans= INT_MAX;

        for(int i=0; i<n; i++){
            if(words[i]== target){
                int dist= abs(i- startIndex);

                ans= min(ans, min(dist, n- dist));
            }
        }
        if(ans== INT_MAX) return -1;
        return ans;
    }
};