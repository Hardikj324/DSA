class Solution {
public:
    // int solver(vector<vector<char>>& matrix,int tx,int ty){
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     if (matrix[tx][ty] == '0') return 0;

    //     int maxside = 1;
    //     bool expand = true;

    //     while(tx+maxside<n && ty+maxside<m && expand){

    //         for(int i = tx;i<=tx+maxside;i++){
    //             if (matrix[i][ty + maxside] == '0') {
    //                 expand = false;
    //                 break;
    //             }
    //         }

    //         for (int j = ty; j <= ty + maxside; j++) {
    //             if (matrix[tx + maxside][j] == '0') {
    //                 expand = false;
    //                 break;
    //             }
    //         }
    //         if (expand) maxside++;

    //     }

    //     return maxside;

    // }

    int solver(vector<vector<char>>& matrix,int i,int j,int &maxi,vector<vector<int>> &dp){
        int n = matrix.size();
        int m = matrix[0].size();

        if (i >= n || j >= m) return 0;
        if (matrix[i][j] == '0') return 0;

        if(dp[i][j]!=-1) return dp[i][j]; 
        
        int right = solver(matrix,i,j+1,maxi,dp);
        int diagnal = solver(matrix,i+1,j+1,maxi,dp);
        int down = solver(matrix,i+1,j,maxi,dp);

        
        dp[i][j] =min(right,min(diagnal,down)) +1 ;
        maxi = max(maxi, dp[i][j]);
        
        return dp[i][j];
        
    }

    int maximalSquare(vector<vector<char>>& matrix) {
    int maxi = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        solver(matrix, i, j, maxi, dp);
        }
    }

    return maxi*maxi;
    }
};