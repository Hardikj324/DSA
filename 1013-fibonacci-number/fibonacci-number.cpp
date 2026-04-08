class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int sum=0;
        int t1=0;
        int t2=1;
         for(int i=0;i<=n;i++){
         sum=sum+t1;
            t1=t2;
            t2=sum;
        }
        return sum;
    }
};