class Solution {
public:
    int n;
    int m;
    int ans = 0;
    void solver(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j){
        if(i<0 || j<0 || n<=i || m<=j){
            return ;
        }
        if(grid[i][j]=='0' || visited[i][j]){
            return ;
        }
        visited[i][j] = true;
        solver(grid,visited,i+1,j);
        solver(grid,visited,i-1,j);
        solver(grid,visited,i,j+1);
        solver(grid,visited,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1' && !visited[i][j]){
                    ans++;
                    solver(grid,visited,i,j);
                }
            }
        }
        return ans;
    }
};