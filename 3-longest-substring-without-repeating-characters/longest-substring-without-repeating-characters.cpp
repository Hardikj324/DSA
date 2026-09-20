class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        int l=0;
        vector<int> lastSeen(256, -1);

        for(int r=0;r<n;r++){
            char c = s[r];

            if(lastSeen[c]>=l){
                l = lastSeen[c]+1;
            }
            lastSeen[c] = r;
            maxi = max(maxi,r-l+1);
        }

        return maxi;
    }
};