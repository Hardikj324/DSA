class Solution {
public:
    int m = 1e9+7;
    int numOfSubarrays(vector<int>& nums) {
        int count = 0;
        int odd = 0;
        int even = 0;
        int n = nums.size();
        vector<int> vec(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                vec[i] = nums[i];
            }
            else{
                vec[i] = (nums[i] + vec[i-1])%m;
            }
        }

        for(int i=0;i<n;i++){
            if(vec[i]%2!=0){
                count =(count+ even)%m;
                odd++;
                count++;
            }
            else{
                count = (count+odd)%m;
                even++;
            }
        }

        return count%m;
    }
};