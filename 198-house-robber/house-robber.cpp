class Solution {
public:
    int rec(vector<int>& nums, int i,vector<int>& dp){
        // Base Condition
    if(i>=nums.size()) return 0;
    if(dp[i] !=-1) return dp[i];

    //Reccurence Reln
    int steal = nums[i] + rec(nums,i+2,dp);
    int skip = 0 + rec(nums,i+1,dp);


    //Return Statement
    dp[i] = max(skip,steal);
    return max(skip,steal);
    }

    int rob(vector<int>& nums) {
        vector<int> dp (nums.size(),-1);
        return rec(nums,0,dp);
    }
};