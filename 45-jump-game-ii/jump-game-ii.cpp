class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int min_jumps = 10005;

        for(int j=1;j<=nums[i];j++){
            int jumps_from_next = solve(nums, i + j, dp);
            if(jumps_from_next!=10005){
                min_jumps = min(min_jumps, 1 + jumps_from_next);
            }
        }
        return dp[i]=min_jumps ;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};