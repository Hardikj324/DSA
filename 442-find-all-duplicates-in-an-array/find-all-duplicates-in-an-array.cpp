class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> result;
       int max = *max_element(nums.begin(),nums.end());
       int n = nums.size();
       int i = 0;
       while(i<n){
        int correct = nums[i] - 1;
        if(nums[i] != nums[correct]){
            swap(nums[i],nums[correct]);
        }
        else{
            i++;
        }
       }

       for(int i = 0; i < n; i++) {

            if(nums[i] != i + 1)
            result.push_back(nums[i]);
        }
    return result;
    }
};