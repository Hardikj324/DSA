class Solution {
public:
    bool isPali(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n  = s.size();
        int ans = 0;
        for(int i=0;i<n;){
            bool found = false;
            if(i+k-1<n && isPali(s,i,i+k-1)){
                ans++;
                found = true;
                i+=k;
            }
            else if(i+k<n && isPali(s,i,i+k)){
                ans++;
                found = true;
                i+=k+1;
            }
            if(!found){
                i++;
            }
        }
        return ans;
    }
};