class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i != col)
            {
                if (board[row][i] == c)
                {
                    return false;
                }
            }
            if (i != row)
            {
                if (board[i][col] == c)
                {
                    return false;
                }
            }
        }
        int boxRowStart = 3 * (row / 3);
        int boxColStart = 3 * (col / 3);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int r = boxRowStart + i;
                int cCol = boxColStart + j;
                if (r == row && cCol == col)
                    continue; // skip the current cell
                if (board[r][cCol] == c)
                    return false;
            }
        }

        return true;
    }

    // Recursive function to solve Sudoku using backtracking
    bool backTrack(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;
                            if (backTrack(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backTrack(board);
    }
};