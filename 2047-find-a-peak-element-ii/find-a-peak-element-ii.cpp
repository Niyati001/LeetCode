class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        int low=0;
        int high= n-1;

        while(low<= high){
            int mid= low +(high- low)/2;

            //max in mid column
            int maxRow=0;
            for(int i=0; i<m; i++){
                if(mat[i][mid]> mat[maxRow][mid]){
                    maxRow=i;
                }
            }
            int left = -1;
            int right = -1;

            if (mid - 1 >= 0) {
                left = mat[maxRow][mid - 1];
            }

            if (mid + 1 < n) {
                right = mat[maxRow][mid + 1];
            }

            if(mat[maxRow][mid]> left && mat[maxRow][mid]> right){
                return {maxRow,mid};
            }
            else if(mat[maxRow][mid]<left){
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return {-1,-1};
    }
};