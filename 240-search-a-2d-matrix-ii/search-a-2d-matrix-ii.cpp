class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int high = m - 1;

        while (high >= 0)
        {
            if (matrix[high][0] <= target && matrix[high][n - 1] >= target)
            {
                int low = 0, second_high = n - 1;
                while (low <= second_high)
                {
                    int mid = (low + second_high) / 2;
                    if (matrix[high][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[high][mid] > target)
                    {
                        second_high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
            }
            high--;
        }

        return false;
    }
};