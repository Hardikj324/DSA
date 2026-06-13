#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current); // store one subset
            return;
        }
        // Choice 1: include nums[index]
        current.push_back(nums[index]);
        backtrack(index + 1, nums, current, result);
        current.pop_back();

        // Choice 2: exclude nums[index]
        backtrack(index + 1, nums, current, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};

