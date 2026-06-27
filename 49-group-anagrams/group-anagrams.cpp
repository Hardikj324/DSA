class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        unordered_map<string,vector<string>> mp;

        for(int i=0;i<n;i++){

          string curr = strs[i];
        sort(curr.begin(),curr.end());
          mp[curr].push_back(strs[i]); 
        }

        for(auto x:mp){
            vector<string> vec;
            
            for(int i=0;i<x.second.size();i++){
                vec.push_back(x.second[i]);
            }
            ans.push_back(vec);
        }   

        return ans;
    }
};