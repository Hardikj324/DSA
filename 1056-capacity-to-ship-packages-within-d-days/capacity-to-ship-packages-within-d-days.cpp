class Solution
{
public:
    int daysNeeded(vector<int> arr, int w)
    {
        int needed_days = 1;
        int currentLoad = 0;
        for (int weight : arr)
        {
            if ((currentLoad + weight) > w)
            {
                needed_days++;
                currentLoad = weight;
            }
            else
            {
                currentLoad += weight;
            }
        }
        return needed_days;
    }
    int shipWithinDays(vector<int> &weights, int d)
    {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while (l <= r)
        {
            int m = (l + r) / 2;
            if (daysNeeded(weights, m) > d)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }
};