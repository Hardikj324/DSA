class Solution
{
public:
    int subdiv(vector<int> &arr, int div)
    {
        int sum = 0;
        for (int num : arr)
        {
            sum += (num + div - 1) / div;
        }
        return sum;
    }

    int smallestDivisor(vector<int> &arr, int limit)
    {
        int l = 1;
        long long r = *max_element(arr.begin(), arr.end());

        int m;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (subdiv(arr, m) > limit)
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