class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m - 1;
        int col = 0;

        while (col < n && row >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] > target)
            {
                row--;
            }
            else
            {
                col++;
            }
        }

        return false;
    }
};