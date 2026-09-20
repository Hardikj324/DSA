class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int count = 0;
        int n = nums.size();
        vector<int> vec(n,0);

        if(n==1){
            return vec;
        }

        int prod = 1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                prod = prod*nums[i];
            }
            else{
                count++;
            }
        }

        if(count>1){
            return vec;
        }

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                vec[i] = prod;
            }

            else if(count==0){
                vec[i] = prod/nums[i];
            }
        }

        return vec; 
    }
};