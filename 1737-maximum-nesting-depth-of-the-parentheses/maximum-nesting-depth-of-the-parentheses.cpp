class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int l=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                l++;
            }
            else if(s[i]==')'){
                l--;
            }
            maxi = max(maxi,l);
        }
        return maxi;
    }
};