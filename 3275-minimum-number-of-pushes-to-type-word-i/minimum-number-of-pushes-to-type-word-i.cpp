class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int t = n/8;
        int rem = n%8;
        int ans = 0;
        if(t>0){
            if(t==1){
                ans += 2*rem;
            }
            else if(t==2){
                ans += 3*rem;
            }
            else{
                ans += 4*rem;
            }
        }
        else{
            ans += 1*rem;
        }
        while(t){
            ans += t*8;
            t--;
        }
        return ans;
    }
};