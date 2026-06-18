class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();

        if(n% groupSize!=0) return false;

        map<int, int> freq;
        sort(hand.begin(), hand.end());

        for(int x: hand){
            freq[x]++;
        }
        for(int x: hand){
            if(freq[x]==0) continue;

            for(int i=0; i< groupSize; i++){
                int card= x+ i;

                if(freq[card]==0) return false;
                freq[card]--;
            }
        }
        return true;
    }
};