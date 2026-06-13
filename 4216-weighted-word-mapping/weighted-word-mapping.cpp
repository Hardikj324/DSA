class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int, char> revAlpha;
        for (int i = 0; i < 26; i++) {
            revAlpha[i] = 'z' - i;
        }
        string ans="";
        for(int i=0;i<words.size();i++){
            int sum=0;
            string word  = words[i];
            for(auto c:word){
                sum += weights[c-'a'];
            }
            sum = sum%26;
            ans.push_back(revAlpha[sum]);
        }

        return ans;
    }
};