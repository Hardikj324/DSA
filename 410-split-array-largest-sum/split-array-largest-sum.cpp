class Solution {
public:
    bool isValid(vector<int> &arr, int Total_sum, int k)
{
    int total_subarray = 1;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (Total_sum < sum)
        {
            return false;
        }
        else if ((arr[i] + sum) <= Total_sum)
        {
            sum = arr[i] + sum;
        }
        else
        {
            total_subarray++;
            sum = arr[i];
        }
    }

    if (total_subarray > k)
    {
        return false;
    }
    return true;
}

int splitArray(vector<int> &nums, int k)
{
    int l = 0;
    int r = accumulate(nums.begin(), nums.end(), 0);
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (isValid(nums, mid, k))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
};