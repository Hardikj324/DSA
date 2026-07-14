class Solution {
public:
    void solver(vector<int> &nums,int i,vector<vector<int>> &res){
        if(i==nums.size()){
            res.push_back(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solver(nums,i+1,res);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solver(nums,0,res);
        return res;
    }
};