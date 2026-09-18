class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        map<int, vector<int>> positions;

        for (int i = 0; i < n; i++) {
            positions[nums[i]].push_back(i);
        }

        int start = 0;

        while(start<n){
            int end = start;

            while(end+1<n && (sorted[end+1] -sorted[end])<= limit){
                end++;
            }
            vector<int> value;
            for(int i=start;i<=end;i++){
                value.push_back(sorted[i]);
            }
            vector<int> indices;
            for(int i=start;i<=end;i++){
                indices.push_back(positions[sorted[i]].back());
                positions[sorted[i]].pop_back();
            }

            sort(indices.begin(),indices.end());
            for(int i=0;i<indices.size();i++){
                nums[indices[i]] = value[i];
            }
            start = end+1;
        }
        return nums;
    }
};