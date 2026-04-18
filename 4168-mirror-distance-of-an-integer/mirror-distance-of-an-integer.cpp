class Solution {
public:
    int reverse(int n) {
    bool neg = n < 0;
    int i = abs(n);
    int reverse_number = 0;

    while (i > 0) {
        int digit = i % 10;
        reverse_number = reverse_number * 10 + digit;
        i = i / 10;
    }

    return neg ? -reverse_number : reverse_number;
}

    int mirrorDistance(int n) {
        int rev = reverse(n);
        return abs(n-rev);
    }
};