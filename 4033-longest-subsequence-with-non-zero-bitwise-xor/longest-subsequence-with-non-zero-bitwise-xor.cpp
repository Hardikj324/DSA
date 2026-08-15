class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int i=0;i<n;i++){
            total^=nums[i];
        }
        if(total!=0){
            return n;
        }

        for(int i:nums){
            if(i!=0){
                return n-1;
            }
        }
        return 0;
    }
};