#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        vector<int> ans;

        // Build map
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int n = nums.size();
        // Process queries
        for (int qi = 0; qi < queries.size(); qi++) {
            int index = queries[qi];
            int value = nums[index];

            vector<int> temp = mp[value];
            if(mp[nums[0]].size()==n && n>1){
                return vector<int>(queries.size(), 1);
            }
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == index) {

                    if ((i - 1) >= 0 && (i + 1) < temp.size()) {
                        int a = abs(temp[i] - temp[i - 1]);
                        int b = abs(temp[i] - temp[i + 1]);
                        int mini = min(a, b);
                        ans.push_back(mini);
                    } else if (i == 0 && (i + 1) < temp.size()) {
                        int a = abs(temp[i] - temp[temp.size() - 1]);
                        int b = abs(temp[i + 1] - temp[i]);
                        a = abs(a-n);
                        int mini = min(a, b);
                        ans.push_back(mini);
                    } else if ((i - 1) >= 0 && (i + 1) >= temp.size()) {
                        int a = abs(temp[i] - temp[i - 1]);
                        int b = abs(temp[i] - temp[0]);
                        b = abs(b-n);
                        int mini = min(a, b);
                        ans.push_back(mini);
                    } else {
                        ans.push_back(-1);
                    }
                }
            }
        }
        return ans;
    }

};