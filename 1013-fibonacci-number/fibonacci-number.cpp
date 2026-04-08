class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int sum=1;
        int t1=0;
        int t2=1;
         for(int i=2;i<=n;i++){
         sum=sum+t1;
            t1=t2;
            t2=sum;
        }
        return sum;
    }
};