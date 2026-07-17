class Solution {
public:
    int solver(vector<vector<int>>& grid,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        if(!(j>=0 && j<=m-3)|| !(i>=0 && i<=n-3)){
            return -1;
        }
        int ans=0;
        ans = grid[i][j] + grid[i+2][j] + grid[i][j+1] + grid[i+2][j+1] + grid[i+1][j+1] + grid[i][j+2] + grid[i+2][j+2];
        return ans;
    }
    int maxSum(vector<vector<int>>& grid) {
        int ans_max = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            ans_max = max(ans_max,solver(grid,i,j));
        }
        }

        return ans_max;
    }
};