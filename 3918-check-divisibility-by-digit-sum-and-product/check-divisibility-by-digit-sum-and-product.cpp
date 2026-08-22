class Solution {
public:
    bool checkDivisibility(int n) {
        int product = 1;
        int sum = 0;
        int m = n;
        while(m){
            int digit = m%10;
            sum+=digit;
            product *=digit;
            m=m/10;
        }

        if(n%(sum+product)==0){
            return true;
        }
        else{
            return false;
        }
    }
};