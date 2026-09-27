class Solution {
public:
    double myPow(double x, int n) {
       long long nn = n;
       if(n<0) nn = -nn;
       double ans = 1.0;

       while(nn){
        if(nn%2==1){
            nn = nn-1;
            ans = ans*x;
        }
        else{
            x = x*x;
            nn = nn/2;
        }
       } 
        if(n<0){
            return 1/ans;
        }
       return ans;
    }
};