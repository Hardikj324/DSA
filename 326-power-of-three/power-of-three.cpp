class Solution {
public:
    bool isPowerOfThree(int n) {
       long long m = n;
       if(m==0) return false;
       while(m!=1){
        cout<<m<<endl;
        if(m%3!=0){
            return false;
        }
        m=m/3;
       }

       return true;
    }
};