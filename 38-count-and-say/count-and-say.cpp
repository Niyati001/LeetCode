class Solution {
public:
    string countAndSay(int n) {
        string result="1";

        for(int i=2; i<=n; i++){
            string temp="";
            int count=1;                              //eg: 111221

            for(int j=1; j<result.size(); j++){
                if(result[j]== result[j-1]){            
                    count++;                              // count=3
                }
                else{
                    temp+= to_string(count);             //3
                    temp+= result[j-1];                  //1     // temp becomes "31"
                    count=1;                             // reset for 2
                }
            }

            temp+= to_string(count);                     // for leftover 1
            temp+= result.back();                        //1
            result= temp;  
        }
        return result;
    }
};