class Solution {
public:
    int maxProduct(int n) {
        int digit1=-1;
        int digit2 = -1;
        while(n){
            int digit = n%10;
            n = n/10;
            if (digit > digit1) {
                digit2 = digit1;
                digit1 = digit;
            } else if (digit > digit2) {
                digit2 = digit;
            }
            }
        return digit1*digit2;
    }
};