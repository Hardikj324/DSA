class Solution {
public:
//whose sum is greater than or equal
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int ans=INT_MAX;
        int n=nums.size();
        int curr_size = 0;
        int curr_sum=0;
        for(int r=0;r<n;r++){
            curr_sum+=nums[r];
            while(curr_sum>=target){
                ans = min(ans, r - l + 1);
                curr_sum -= nums[l];
                l++;
            }
        }

    return (ans == INT_MAX) ? 0 : ans;

    }
};