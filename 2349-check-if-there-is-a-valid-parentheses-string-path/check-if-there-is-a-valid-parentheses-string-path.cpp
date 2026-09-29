class Solution {
public:
    int n;
    int m;
    bool solver(int i,int j,int bal,vector<vector<char>>& grid,vector<vector<vector<int>>> &dp){
        if(i >= n || j >= m)
            return false;
       
       if(grid[i][j]=='('){
        bal++;
       }
       else{
        bal--;
       }
       if(bal<0){
        return false;
       }
       if(i == n-1 && j == m-1)
            return bal == 0;

        if(dp[i][j][bal]!=-1){
            return dp[i][j][bal];
        }
        
        return dp[i][j][bal] =solver(i + 1, j, bal, grid,dp) ||solver(i, j + 1, bal, grid,dp);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>>dp (n,vector<vector<int>>(m,vector<int>(m+n-1,-1)));
        return solver(0,0,0,grid,dp);
    }
};