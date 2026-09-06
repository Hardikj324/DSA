class Solution {
public:
    int solver(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;

        if (dp[j][i] != -1) return dp[j][i];

        if (dp[j][i] != -1) return dp[j][i];

        int ways = 0;
        if(s[i]==t[j]){
            ways+=solver(s,t,i+1,j+1,dp);
        }
        ways+=solver(s,t,i+1,j,dp);

        return dp[j][i] = ways;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size(), vector<int>(s.size(), -1));
        return solver(s, t, 0, 0, dp);
    }
};
