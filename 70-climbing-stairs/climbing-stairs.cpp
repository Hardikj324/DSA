class Solution {
public:
    int solver(int n,int curr,vector<int> &dp){
        if(curr==n){
            return 1;
        }
        else if(curr>n){
            return 0;
        }
        if(dp[curr]!=-1) return dp[curr];
        return dp[curr] = solver(n,curr+1,dp) + solver(n,curr+2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solver(n,0,dp);

    }
};