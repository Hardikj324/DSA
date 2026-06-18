class Solution {
public:
    double angleClock(int hour, int minutes) {
        double n = hour*30 + minutes*0.5;
        double m = minutes*6;
        double ans= abs(n-m);

        return (ans>180) ? 360-ans:ans;
    }
};