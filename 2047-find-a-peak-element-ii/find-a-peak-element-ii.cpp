class Solution
{
public:
    int maxElement(vector<vector<int>> &arr, int col)
    {
        int n = arr.size();
        int max_val = INT_MIN;
        int index = -1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i][col] > max_val)
            {
                max_val = arr[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        int high = m - 1;
        int low = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int row = maxElement(arr, mid);
            int max_element = arr[row][mid];
            int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;

            if (left < max_element && max_element > right)
            {
                return {row, mid};
            }
            else if (left > arr[row][mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};
