class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int j=0;
        int ans = 0; 
        for(int i=0;i<n ;i++){
             mp[nums[i]]++;
            while(mp[nums[i]]>k && j<i){
                mp[nums[j]]--;
                j++;
            }
           
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};