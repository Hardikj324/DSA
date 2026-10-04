class Solution {
public:
    int from_to(char f,char t){
        int rotation = 0;

        int a =  f - '0';
        int b = t - '0';

        rotation = min((10 -abs(a-b)),abs(a-b));

        return rotation;

    }

    int minRotations(int n, string s) {
        int total = from_to('0', s[0]);

        for (int i = 1; i < n; i++) {
            total += from_to(s[i - 1], s[i]);
        }

        int ans = total;
        char prev = '0';
        for(int i=0;i<n;i++){
            int currTotal = total - from_to(prev,s[i]) + from_to(s[n-1],prev);
            prev = s[i];

            ans = min(ans,currTotal);
        }

        return ans;
    }
};