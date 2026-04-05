class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int first = -1;
        int last = -1;
        int m = 0;

        if (nums.empty())
            return {-1, -1};

        while (l <= h)
        {
            m = l + (h - l) / 2;
            if (nums[m] > target)
            {
                h = m - 1;
            }
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else if (nums[m] == target)
            {
                last = m;
                l = m + 1;
            }
        }

        if (last == -1)
        {
            return {first, last};
        }

        else
        {
            l = 0;
            h = nums.size() - 1;
            while (l <= h)
            {
                m = l + (h - l) / 2;
                if (nums[m] > target)
                {
                    h = m - 1;
                }
                else if (nums[m] < target)
                {
                    l = m + 1;
                }
                else if (nums[m] == target)
                {
                    first = m;
                    h = m - 1;
                }
            }
        }
        return {first, last};
    }
};