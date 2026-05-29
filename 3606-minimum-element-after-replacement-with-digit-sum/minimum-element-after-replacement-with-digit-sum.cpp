class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int curr = 0;
            int m = nums[i];
            while(m){
                curr += m%10;
                m =m/10;
            }

            mini = min(curr,mini);
        }

        return mini;
    }
};