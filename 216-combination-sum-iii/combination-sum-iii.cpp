class Solution {
public:
    void func(int sum, int last, vector<int> &nums, int k, vector<vector<int>> &ans)
    {
        if (sum == 0 && k == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        if (last > 9 || sum < 0 || k < nums.size())
        {
            return;
        }

        nums.push_back(last);
        func(sum - last, last + 1, nums, k, ans);
        nums.pop_back();
        func(sum, last + 1, nums, k, ans);
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums;
        func(n, 1, nums, k, ans);
        return ans;
    }
};