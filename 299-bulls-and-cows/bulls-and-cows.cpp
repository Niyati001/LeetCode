class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows=0;
        vector<int> freq(10, 0);

        for(int i=0; i<secret.size(); i++){
            if(secret[i]== guess[i])
               bulls++;
            else
                freq[secret[i]- '0']++;
        }

        for(int i=0; i<guess.size(); i++){
            if(secret[i]== guess[i])
                continue;

            int digit= guess[i]- '0';

            if(freq[digit]>0){
                cows++;
                freq[digit]--;
            }
        }
        return to_string(bulls) + "A"+ to_string(cows)+ "B";
    }
};