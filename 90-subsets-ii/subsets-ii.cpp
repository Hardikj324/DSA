class Solution {
public:
    set<vector<int>> st;
    void solver(vector<int>& nums,vector<int>& temp,vector<vector<int>> &ans,int i){
        if(i==nums.size()){
            if(!st.count(temp)){
                st.insert(temp);
                ans.push_back(temp);
            }
            return ;
        }

        temp.push_back(nums[i]);
        solver(nums,temp,ans,i+1);

        temp.pop_back();
        solver(nums,temp,ans,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solver(nums,temp,ans,0);
        return ans;
    }
};


