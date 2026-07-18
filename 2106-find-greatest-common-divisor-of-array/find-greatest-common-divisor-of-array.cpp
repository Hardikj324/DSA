class Solution {
public:
    int gcd(int n,int m){
        if(m==0){
            return n;
        }
        else{
            return gcd(m,n%m);
        }
    }
    int findGCD(vector<int>& nums) {
        int smallest = *min_element(nums.begin(),nums.end());
        int gratest = *max_element(nums.begin(),nums.end());

        return gcd(smallest,gratest);

    }
};