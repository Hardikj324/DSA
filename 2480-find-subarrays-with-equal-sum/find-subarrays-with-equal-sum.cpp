class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        int j = 0;
        long long curr = 0;
        for(int i=0;i<n;i++){
            curr +=nums[i];
            while(i-j+1>2){
                curr -=nums[j];
                j++;
            }

            if((i-j+1)==2 && st.count(curr)){
                return true;
            }

            if((i-j+1)==2){
                st.insert(curr);
            }

        }
        return false;
    }
};