class Solution {
public:
    //We are creating the subarray with at most at most k zeros. 
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count_k =0;
        int maxi = INT_MIN;
        int l=0;
        int r = 0;
        while(r<n){
            if(nums[r]==0) count_k++;
            while(count_k>k){
                if(nums[l]==0) count_k--;
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};