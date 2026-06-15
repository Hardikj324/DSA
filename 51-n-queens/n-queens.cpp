class Solution {
public:
    bool isSafe(vector<string> &temp, int i, int row, int n)
{
    // Check for the same row
    for (int j = 0; j < n; j++)
    {
        if (j == i)
            continue;
        if (temp[row][j] == 'Q')
            return false;
    }
    // Check for the same col
    for (int j = 0; j < n; j++)
    {
        if (j == row)
            continue;
        if (temp[j][i] == 'Q')
            return false;
    }
    // Check for the same diagonal(left)
    for (int j = i - 1, y = row - 1; j >= 0 && y >= 0; j--, y--)
    {
        if (temp[y][j] == 'Q')
            return false;
    }
    // Check for the same diagonal(right)
    for (int j = i + 1, y = row - 1; j < n && y >= 0; j++, y--)
    {
        if (temp[y][j] == 'Q')
            return false;
    }

    return true;
}

void helper(vector<vector<string>> &board, int row, int n, vector<string> temp)
{
    if (row == n)
    {
        board.push_back(temp);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(temp, i, row, n))
        {
            temp[row][i] = 'Q';
            helper(board, row + 1, n, temp);
            temp[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> board;
    vector<string> temp(n, string(n, '.'));
    helper(board, 0, n, temp);
    return board;
}
};