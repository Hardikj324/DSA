class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();

        int total = 0;
        for(int num : nums)
            total += num;

        int target = total - x;

        if(target < 0) return -1;
        if(target == 0) return n;

        int i = 0;
        int curr = 0;
        int maxLen = -1;

        for(int j = 0; j < n; j++) {

            curr += nums[j];

            while(curr > target) {
                curr -= nums[i];
                i++;
            }

            if(curr == target) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        if(maxLen == -1) return -1;

        return n - maxLen;
    }
};



