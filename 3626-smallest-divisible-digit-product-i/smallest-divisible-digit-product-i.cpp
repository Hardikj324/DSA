class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=0;i<t;i++){
            int temp = n +i;
            int product = 1;

            while(temp){
                int digit = temp%10;
                product *= digit;
                temp = temp/10;
            }

            if(product%t==0){
                return n + i;
            }

        }
        return n;
    }
};