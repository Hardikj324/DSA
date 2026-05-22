class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        long long int product = 1;
        int left=0;

        for(int right=0;right<n;right++){
            product*=nums[right];
            while(product>=k && left<=right){
                product /=nums[left];
                left++;
            }
            count +=  (right-left+1);
        }
        return count;
    }
};