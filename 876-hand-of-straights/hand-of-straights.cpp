class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()% groupSize!=0) return false;

        map<int, int> mp;

        for(int x: hand){
            mp[x]++;
        }
        for(auto &it: mp){
            int num= it.first;
            int count= it.second;

            while(mp[num]>0){
                for(int i=0; i<groupSize; i++){
                    int curr= num+i;
                    if(mp[curr]== false) return false;
                    mp[curr]--;
                }
            }
        }
        return true;
    }
};