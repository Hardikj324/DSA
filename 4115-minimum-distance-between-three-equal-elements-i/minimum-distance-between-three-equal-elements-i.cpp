class Solution {
public:
    int minimumDistance(vector<int>& nums) {
         int res = INT_MAX;
        unordered_map<int, vector<int>> mp;  
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);  
        }

        for (auto& arr : mp) {
            auto& v = arr.second;

            if (v.size()>= 3) {  
                for(int i=0;i+2<v.size();i++){
                    int mini = 2*abs(v[i+2]-v[i]);
                    res = min(mini, res);
                }

                
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};