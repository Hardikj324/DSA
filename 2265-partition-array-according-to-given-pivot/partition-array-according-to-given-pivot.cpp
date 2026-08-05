class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int ls=0,gd=0,eq=0;
        for(int i:nums){
            if(i<pivot)ls++;
            else if(i>pivot)gd++;
            else eq++;
        }

        vector<int> ans(n);
        int i=0,p=ls,j=ls+eq;

        for(auto &n:nums){
            if(n<pivot){
                ans[i++] = n;
            }
            else if(n>pivot){
                ans[j++] = n;
            }
            else{
                ans[p++] = n;
            }
        }
        return ans;
    }
};