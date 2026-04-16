class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            int val = nums[q];
            auto &indices = mp[val];

            if (indices.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(indices.begin(), indices.end(), q) - indices.begin();

            int left = indices[(pos - 1 + indices.size()) % indices.size()];
            int right = indices[(pos + 1) % indices.size()];

            int dist_left = abs(q - left);
            dist_left = min(dist_left, n - dist_left);

            int dist_right = abs(q - right);
            dist_right = min(dist_right, n - dist_right);

            ans.push_back(min(dist_left, dist_right));
        }

        return ans;
    }
};