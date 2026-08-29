class Solution {
public:
    int ans = 0;
    int solver(int ind,int prev,vector<int> &num,vector<vector<int>> &dp){
        if(ind>=num.size()){
            return 0;
        }

        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }

        int take = 0;
        if(prev==-1||num[ind]>num[prev]){
            take = solver(ind+1,ind,num,dp) + 1;
        }

        int skip = solver(ind+1,prev,num,dp);

        return dp[ind][prev+1] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solver(0, -1, nums, dp);
        return ans;

    }
};