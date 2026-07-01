class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int> mp;
        int left = 0;
        int diff_ele = 0;
        int count = 0;
        for(int right=0;right<n;right++){
            if(mp[nums[right]]==0) diff_ele++;
            mp[nums[right]]++;
            // cout<<"Left :"<<left<<" Right :"<<right<<" different element :"<<diff_ele<< " Count :"<<count<<endl;

            while(diff_ele>k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) diff_ele--;
                left++;
            }

            count+=(right-left+1);
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};