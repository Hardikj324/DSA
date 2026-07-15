class Solution {
public:
    int gcd(int n,int m){
        if(m==0 || n==m){
            return n;
        }
        else{
            return gcd(m,n%m);
        }
    }
    int gcdOfOddEvenSums(int n) {
        int i=0;
        int odd=0;
        int even=0;
        int odd_sum=0;
        int even_sum=0;
        while((even+odd)!=2*n){
            if(odd<n && i%2==1){
                odd_sum+=i;
                odd++;
            }
            if(even<n && i%2==0){
                even_sum+=i;
                even++;
            }
            i++;
        }

        return gcd(odd_sum,even_sum);
    }
};