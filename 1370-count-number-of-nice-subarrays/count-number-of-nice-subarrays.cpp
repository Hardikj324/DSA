class Solution {
public:
    int atMost(vector<int> nums,int k){
        int n = nums.size();
        int left=0,count=0,odds=0;
        for(int right=0;right<n;right++){
            if(nums[right]%2) odds++;
            while(odds>k){
                if(nums[left]%2) odds--;
                left++;
            }

            count += (right-left+1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }

};