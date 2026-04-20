class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi=INT_MIN;
        int n=arr.size()-1;
        vector<int> nums(n+1,0);
        for(int i=n;i>=0;i--){
            if(i!=n){
                nums[i] = maxi;
            }
            else{
                nums[i] = -1;
            }
            maxi = max(maxi,arr[i]);
        }
        return nums;
    }
};