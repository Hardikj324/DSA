class Solution {
public:
    int M = 1e9+7;
    int power(long long b,long long e){
        long long ans = 1;

        while (e > 0) {
            if (e % 2 == 1) {
                ans = (ans * b)%M;
            }

            b = (b * b)%M;
            e /= 2;
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
        
        long long oddp = n/2;
        long long evenp = (n+1)/2;
        long long evenWays = power(5, evenp);
        long long oddWays = power(4, oddp);
        return ( evenWays * oddWays)%M ;
    }
};