class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]%k==0) st.insert(nums[i]);
        }

        for(int i=0;i<n+1;i++){
            if(!st.count(k*(i+1))){
                ans = k*(i+1);
                break;
            }
        }

        return ans;
    }
};