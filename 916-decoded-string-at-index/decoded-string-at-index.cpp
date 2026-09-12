class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size=0;

        //find length of decoded string
        for(char ch: s){
            if(isdigit(ch))
                size*= (ch-'0');
            else 
                size++;
        }

        // work backwards
        for(int i= s.size()-1; i>=0; i--){
            char ch= s[i];

            if(isdigit(ch)){
                int d= ch-'0';
                size/= d;
                k%= size; 

                if(k==0)
                    k= size;
            }
            else{
                if(k== size)
                    return string(1, ch);
                
                size--;
            }
        }
        return "";
    }
};