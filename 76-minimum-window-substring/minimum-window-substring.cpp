class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> v(64,0);
        for(auto x:t){
            v[x-'A']++;
        }
        int l=0;
        int start=0,cnt=0,len = INT_MAX;
        for(int r=0;r<n;r++){
            char c = s[r];
            if(v[c-'A']>0){
                cnt++;
            }
            v[c-'A']--;
            while(cnt==m){
                if(r-l+1<len){
                    len = r-l+1;
                    start = l;
                }
                v[s[l]-'A']++;
                if(v[s[l]-'A']>0) cnt--;
                l++;
            }
        }
        if(len==INT_MAX) return "";
        return s.substr(start,len);
    }
};