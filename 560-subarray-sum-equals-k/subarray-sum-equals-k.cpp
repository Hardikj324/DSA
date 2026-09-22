class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec(n,0);
        unordered_map<int,int> mp;
        vec[0] = nums[0];
        int count  = 0;
        for(int i=1;i<n;i++){
            vec[i] = vec[i-1] + nums[i];
        }

        for(int i=0;i<n;i++){
            if(vec[i]-k==0){
                count++;
            }
            if(mp.find(vec[i]-k)!=mp.end()){
                count+=mp[vec[i]-k];
            }
            mp[vec[i]]++;
        }
        return count;
    }
};