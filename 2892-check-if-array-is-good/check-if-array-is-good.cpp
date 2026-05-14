class Solution {
public:
    bool isGood(vector<int>& nums) {
        int count = 0;
        int p=nums.size();
        int n=p-1;
        vector <int> ind(p,0);
        for(int i=0;i<p;i++){
            if(nums[i]>n){
                return false;
            }
            ind[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(ind[i]>=2){
                return false;
            }
        }

        return ind[n]==2;
    }
};