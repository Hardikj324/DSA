class Solution {
public:
    int n;
    int m;
    bool solver(vector<vector<int>>& grid,int i,int j){
        if(grid[i][j]==1){
            return true;
        }

        if(grid[i][j]==0 && ( i==0 || i==n-1 || j==0 || j==m-1 )){
            return false;
        }

        grid[i][j] = 1;
        bool up = solver(grid,i-1,j); 
        bool down = solver(grid,i+1,j);
        bool left = solver(grid,i,j-1);
        bool right = solver(grid,i,j+1);

        return up && down && right && left;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0){
                    if(solver(grid,i,j)){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};