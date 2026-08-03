class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int count = 0;
        int n = tokens.size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        while(i<=j){
            if(power>=tokens[i]){
                count++;
                power-=tokens[i];
                i++;
            }
            else{
                if(count>0){
                    count--;
                    power +=tokens[j];
                    j--;
                }
                else{
                    break;
                }
            }
            ans = max(ans,count);
        }

        return ans;
    }
};