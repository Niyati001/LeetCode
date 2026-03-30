class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int addCount=0;
        for(char c: s){
            if(c== '('){
                count++;
            }
            else{
                count--;
            }
            if(count<0){
                addCount++;
                count=0;
            }
        }
         return addCount+ count;
    }
};

        