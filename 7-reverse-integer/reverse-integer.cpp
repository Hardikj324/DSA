class Solution {
public:
    int reverse(int x) {
        long long ans = 0;   
        int sign = (x < 0) ? -1 : 1;
        long long n = abs((long long)x); 

        while (n) {
            int digit = n % 10;
            n /= 10;
            ans = ans * 10 + digit;
        }

        ans *= sign;

        if (ans < INT_MIN || ans > INT_MAX) return 0;
        return (int)ans;
    }
};