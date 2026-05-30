class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                mp[nums[i]] = i;
            }
        }

        for(int i=1;i<=nums.size()+1;i++){
            if(mp.find(i) == mp.end()){
                ans = i;
                break;
            }
        }

        return ans;
    }
};