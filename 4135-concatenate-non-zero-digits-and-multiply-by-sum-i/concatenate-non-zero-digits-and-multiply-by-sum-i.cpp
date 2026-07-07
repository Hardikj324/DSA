class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long place = 1;

        while (n > 0) {
        int digit = n % 10;
        if (digit != 0) {
            x += 1LL* digit * place;
            place *= 10;
            sum+=digit;
        }
        n /= 10;
    }

        return x*sum;
    }
};