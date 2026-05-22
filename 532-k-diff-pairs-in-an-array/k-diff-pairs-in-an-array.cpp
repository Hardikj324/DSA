class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int diff;
        int i=0;
        int j=1;
        int count =0;

        unordered_set <int> check;

        while(j<n){

            if (i == j) {
                j++;
                continue;
            }

            diff = nums[j] - nums[i];

            if(diff==k){
                if(check.find(nums[i])==check.end() || check.find(nums[j])==check.end()){
                count++;
                check.insert(nums[i]);
                check.insert(nums[j]);
                }
                if(check.find(nums[i])==check.end()){
                    i++;
                }
                else if(check.find(nums[j])==check.end()){
                    j++;
                }
                else{
                    i++;
                    j++;
                }

            }
            if(diff>k){
                i++;
            }
            else if(diff<k){
                j++;
            }
        }
        return count;
    }
};