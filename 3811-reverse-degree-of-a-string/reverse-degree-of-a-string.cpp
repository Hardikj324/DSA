class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int i=1;
        for(auto c:s){
            int digit = 26- (c-'a');
            ans = ans + digit*(i);
            i++;
        }
        return ans;
    }
};