class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini;
        int maxi;
        
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        for(int i=0;i<n;i++){
            int curr=nums[i];
            if(min_val>curr){
                min_val = curr;
                mini = i;
            }
            if(max_val<curr){
                maxi = i;
                max_val = curr;
            }
        }
        int left = max(mini, maxi) + 1;

        int right = n - min(mini, maxi);

        int both = min(mini, maxi) + 1 + n - max(mini, maxi);

        return min({left, right, both});
    }
};