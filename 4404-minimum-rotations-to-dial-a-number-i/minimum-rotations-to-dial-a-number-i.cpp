class Solution {
public:
    int from_to(char f,char t){
        int rotation = 0;

        int a =  f - '0';
        int b = t - '0';

        rotation = min((10 -abs(a-b)),abs(a-b));

        return rotation;

    }
    int minRotations(string s) {
        int ans = 0;
        char prev = '0';
        for(int i=0;i<s.size();i++){
            ans += from_to(prev,s[i]);
            prev = s[i];
        }
        return ans;
    }
};