class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();

        bool firstRowZero= false;
        bool firstColZero= false;

        // checking rows
        for(int j=0; j<n; j++){
            if(matrix[0][j]== 0){
                firstRowZero= true;
                break;
            }
        }

        // checking columns
        for(int i=0; i<m; i++){
            if(matrix[i][0]== 0){
                firstColZero= true;
                break;
            }
        }

        //use first row and column as markers
        for( int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if( matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        // set cells to 0 based on markers
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        // zero out first row and column if needed
        if(firstRowZero){
            for(int j=0; j<n; j++){
                matrix[0][j]=0;
            }
        }

        if(firstColZero){
            for(int i=0; i<m; i++){
                matrix[i][0]= 0;
            }
        }
    }
};

// time comp: O(m*n)
// space: O(1)