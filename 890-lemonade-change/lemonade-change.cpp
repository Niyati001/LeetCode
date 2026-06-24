class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;

        for(int bill: bills){
            if(bill==5){
                five++;
            }
            if(bill==10){
                ten++;
                if(five) five--;
                else return false;
            }
            if(bill==15){
                if(ten) ten--;
                else if(five>1){
                    five-=2;
                }
                else return false;
            }
            if(bill==20){
                if(five && ten) {
                    five--; ten--;
                }
                else if(five>2) five-=3;
                else return false;
            }
        }
        return true;
    }
};