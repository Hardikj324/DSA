class Solution {
public:
    int no_of_expression(vector<int>& nums, int target,int index,int curr,vector<vector<int>> &dp,int totalSum){
        if (index == nums.size()) {
            return curr == target;
        }

        int dpIndex = curr + totalSum;

        if(dp[index][dpIndex]!=-1){
            return dp[index][dpIndex];
        }


        int pos = no_of_expression(nums,target,index+1,curr+nums[index],dp,totalSum);

        int neg = no_of_expression(nums,target,index+1,curr-nums[index],dp,totalSum);

        return dp[index][dpIndex] = pos + neg;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int curr = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2*totalSum +1 ,-1));
        return no_of_expression(nums, target,0,curr,dp,totalSum);
    }
};