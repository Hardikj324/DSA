class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> vec;
        int less = 0;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<target){
                less++;
            }
            else if(nums[i]==target){
                count++;
            }
        }

        for(int i=0;i<count;i++){
            vec.push_back(less);
            less++;
        }
    return vec;
    }
};