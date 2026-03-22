class Solution {
public:
    int revers_a_number(int n)
    {
        long long revers_number = 0;
        while (n > 0)
        {
            int digit = n % 10;
            n = n / 10;
            revers_number = revers_number * 10 + digit;
        }
        return revers_number;
    }
    bool isPalindrome(int n) {
        int reverse = revers_a_number(n);
    if (reverse == n)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
};