class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 1, h = n - 2;
        int m;
        if (n == 1)
            return 0;
        if (nums[0] > nums[l])
            return 0;
        if (nums[n - 1] > nums[h])
            return n - 1;

        while (l <= h)
        {
            m = (l + h) / 2;
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
                return m;
            else if (nums[m] < nums[m + 1])
            {
                l = m + 1;
            }
            else if (nums[m] < nums[m - 1])
            {
                h = m - 1;
            }
        }
        return -1;
    }
};