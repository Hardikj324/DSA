class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mid = n/2;
        int ele = nums[mid];
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += abs(ele-nums[i]);
        }

        return sum;
    }
};