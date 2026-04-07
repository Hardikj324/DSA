class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_ind=0;
        int max_count=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
        }
        if(max_count<count){
                    max_ind=i;
                }
                max_count = max(count,max_count);
        
        }
        return max_ind;
    }
};