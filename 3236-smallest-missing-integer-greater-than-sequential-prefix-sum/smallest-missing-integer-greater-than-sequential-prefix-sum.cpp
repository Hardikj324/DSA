class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int curr_sum = nums[0];
        int i = 1;
        
        while (i < nums.size() && nums[i] == nums[i-1] + 1) {
            curr_sum += nums[i];
            i++;
        }

         unordered_set<int> s(nums.begin(), nums.end());


        while (s.count(curr_sum)) {
            curr_sum++;
        }
        
        return curr_sum;
    }
};