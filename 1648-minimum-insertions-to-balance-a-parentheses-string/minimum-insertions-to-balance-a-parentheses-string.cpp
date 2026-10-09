class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        int n = s.size();
        int ans = 0;
        int i = 0;
        while(i<n){
            if(s[i]=='('){
                count++;
                i++;
            }
            else{
                if(i<n-1 && s[i+1]==')'){
                    count--;
                    i = i+2;
                }
                else{
                    ans++;
                    count--;
                    i++;
                }
            }
            if(count<0){
                ans +=abs(count);
                count = 0;
            }

        }

        return ans + count*2;
    }
};