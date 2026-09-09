class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long one = n - 999;
        long long two = (n - 999999)  ;
        long long three = (n - 999999999) ;
        long long four = (n - 999999999999) ;
        long long five = (n - 999999999999999) ;
        long long ans = 0;
        
        if(one>0) ans +=one;
        if(two>0) ans+=two;
        if(three>0) ans +=three;
        if(four>0) ans+=four;
        if(five>0) ans+=five;

        return ans;
    }
};