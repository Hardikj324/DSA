class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(51,0);
        for(int i=0;i<=n-k;i++){
            vector<bool> seen (51,false);

            for(int j=i;j<i+k;j++){
                if(!seen[nums[j]]){
                    seen[nums[j]] = true;
                    freq[nums[j]]++;
                }
            }
        }
        int ans = -1;
        for(int j=50;j>=0;j--){
            if(freq[j]==1){
                ans = j;
                break;
            }
        }
        return ans;
    }
};