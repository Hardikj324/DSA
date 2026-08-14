class Solution {
public:
    int maximumLengthSubstring(string s) {
        int j=0;
        int n = s.size();
        int ans = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[j]]--;
                j++;
            }
            ans = max(ans,i-j+1);
        }

        return ans;
    }
};