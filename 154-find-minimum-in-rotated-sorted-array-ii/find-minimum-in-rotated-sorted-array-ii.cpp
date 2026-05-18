class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int m;
        while(l<h){
            m = (l+h)/2;
           if(nums[m] > nums[h]){
                l = m + 1;
            } else if(nums[m] < nums[h]) {
                h = m;
            }
            else{
                h--;
            }
        }
        return nums[l];
    }
};