class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n= row.size();
        int swaps=0;

        vector<int> pos(n);

        for(int i=0; i<n; i++){
            pos[row[i]]=i;
        }

        for(int i=0; i<n; i+=2){
            int first= row[i];

            int partner= first^1;

            if(row[i+1]== partner)
                continue;
            
            int partnerPos= pos[partner];

            int other= row[i+1];

            swap(row[i+1], row[partnerPos]);

            pos[partner]= i+1;
            pos[other]= partnerPos;

            swaps++;
        }
        return swaps;
    }
};