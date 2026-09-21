class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        
        unordered_map<string,vector<string>> mp;

        for(int i=0;i<n;i++){
            string str = strs[i];

            vector<int> vec(26,0);
            for(int j=0;j<str.size();j++){
                vec[str[j]-'a']++;
            }

            string map_str = "";
            for(int j = 0; j < 26; j++) {
                char c = 'a' + j;

                for(int k = 0; k < vec[j]; k++) {
                    map_str.push_back(c);
                }
            }
            mp[map_str].push_back(str);
        }

        for(auto m:mp){
            result.push_back(m.second);
        }

        return result;
    }
};