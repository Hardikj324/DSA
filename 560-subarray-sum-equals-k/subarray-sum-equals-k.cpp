class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int array_len = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];

            if (sum == k)
            {
                array_len++;
            }

        }
    }

    return array_len;
    }
};