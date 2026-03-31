class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> arr;

    int i = 0;
    while (i < n)
    {
        int start = nums[i][0];
        int end = nums[i][1];
        while (i + 1 < n && nums[i + 1][0] <= end)
        {
            end = max(nums[i + 1][1], end);
            i++;
        }
        arr.push_back({start, end});
        i++;
    }

    return arr;
    }
};