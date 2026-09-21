class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> vec;
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int sum;
            int k =n-1;
            int j = i+1;
            while(j<k){
                sum = nums[k] + nums[j] + nums[i];
                if(sum>0){
                    sum -=nums[k];
                    k--;
                }
                else if(sum<0){
                    sum -=nums[j];
                    j++;
                }
                else {
                    vec.push_back({nums[i],nums[j],nums[k]});

                    while( j<k && nums[j]==nums[j+1]) j++;
                    while( j<k && nums[k]==nums[k-1]) k--;

                    j++;
                    k--;
                    
                }
            }
        } 

        return vec;
    }
};