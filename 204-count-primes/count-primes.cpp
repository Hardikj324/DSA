class Solution {
public:
    int countPrimes(int val)
    {
        //Sieve of Eratosthenes 
        vector<bool> isPrime(val+1,true);
        int count = 0;
        for(int i=2;i<val;i++){
            if(isPrime[i]) {count++;
            for(int j = i*2;j<val;j=j+i){
                isPrime[j] = false;
            }
            }
        }
        return count;
    }
};