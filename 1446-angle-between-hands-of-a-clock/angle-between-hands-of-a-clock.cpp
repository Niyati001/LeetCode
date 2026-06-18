class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle= 6.0*minutes;
        double hourAngle= 30.0*(hour%12) + 0.5*minutes;

        double diff= abs(hourAngle- minAngle);
        return min(diff, 360.0- diff);
    }
};