class Solution {
public:
    bool solve(vector<int>& nums,int i,vector<int> &dp){
        if(i==nums.size()-1){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
            for(int z = 1; z <= nums[i]; z++){ 
            if((i + z) < nums.size()){
                if(solve(nums, i + z,dp)){
                    return dp[i] = 1;
                }
            }
        }

        return dp[i]=0;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};