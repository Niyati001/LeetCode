class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m= mat.size();
        int n= mat[0].size();

        vector<pair<int, int>> rows;

        for(int i=0; i<m; i++){
            int left=0;
            int right= n;

            while(left< right){
                int mid= left+ (right-left)/2;

                if(mat[i][mid]== 1)
                    left= mid+1;
                else
                    right= mid;
            }
            int soldiers= left;
            rows.push_back({soldiers, i});
        }
        sort(rows.begin(), rows.end());

        vector<int> ans;

        for(int i=0; i<k; i++){
            ans.push_back(rows[i].second);
        }
        return ans;
    }
};