class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> v(26,0);

        for(int i=0;i<n;i++){
            int val = text[i] - 'a';
            v[val]++;
        }

        string temp = "balloon";
        int ans =INT_MAX;
        for(int i=0;i<temp.size();i++){
            int val;
            int asc = temp[i] - 'a';
            val = v[asc];
            if(temp[i]=='l' || temp[i]=='o'){
                val = val/2;
            }
            ans = min(ans,val);

        }
    return ans;
    }
};