class Solution {
public:
    int gcd(int a,int b){
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int maxLength(vector<int>& nums) {
        int res = 2;
        int prodVal = 1;
        int n = nums.size();
        int start = 0, end =0;

        while(end<n){
            while(gcd(prodVal,nums[end])>1){        //All the number in the subarray should pairwise co prime!!
                prodVal /= nums[start];
                start++;
            }
            prodVal *= nums[end];
            res = max(res, end - start + 1);
            end++;
        }
        return res;
    }
};