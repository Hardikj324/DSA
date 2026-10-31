class Solution {
public:
    int n;
    int m;
    long long mod = 1e9 + 7;

    int solver(vector<vector<int>>& grid, int i, int j, int dir,
               vector<vector<vector<int>>>& dp) {
        if (i >= n || j >= m) {
            return 0;
        }

        if (dp[i][j][dir] != -1) {
            return dp[i][j][dir];
        }

        // current cell is a mirror: no choice, forced move
        if (grid[i][j] == 1) {
            if (dir == 0) {
                return dp[i][j][dir] = solver(grid, i + 1, j, 1, dp);  // right -> down
            } else {
                return dp[i][j][dir] = solver(grid, i, j + 1, 0, dp);  // down -> right
            }
        }

        // current cell is empty
        if (i == n - 1 && j == m - 1) {
            return 1;
        }

        long long down  = solver(grid, i + 1, j, 1, dp);
        long long right = solver(grid, i, j + 1, 0, dp);

        return dp[i][j][dir] = (down + right) % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        return solver(grid, 0, 0, 0, dp);
    }
};