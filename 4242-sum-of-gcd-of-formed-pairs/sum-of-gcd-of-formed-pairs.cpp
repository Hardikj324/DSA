class Solution {
public:
    long long gcd(int n,int m){
        if(m==0){
            return n;
        }
        else{
            return gcd(m,n%m);
        }
    }
    long long gcdSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int  max_el=0;
        vector<int> prefixGcd(n);

        for(int i=0;i<n;i++){
            max_el = max(max_el,nums[i]);
            prefixGcd[i] = gcd(max_el,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());


        for(int i=0;i<n/2;i++){
            ans += gcd(prefixGcd[i],prefixGcd[n-i-1]);
        }

        return ans;
    }
};