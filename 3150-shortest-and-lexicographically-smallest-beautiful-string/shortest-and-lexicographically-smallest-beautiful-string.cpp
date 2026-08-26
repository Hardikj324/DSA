class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int mini = INT_MAX;
        int n = s.size();
        int i = 0;
        int curr_len = 0;
        int no_of_ones = 0;
        for(int j=0;j<n;j++){
            char c = s[j];
            if(c=='1') no_of_ones++;

            while(i<=j && (s[i]=='0'||no_of_ones>k) ){
                c = s[i];
                if(c=='1') no_of_ones--;
                i++; 
            }

            if (no_of_ones == k) {
                int curr_len = j - i + 1;
                string curr = s.substr(i, curr_len);

                if (curr_len < mini) {
                    mini = curr_len;
                    ans = curr;
                } else if (curr_len == mini) {
                    ans = min(ans, curr); 
                }
            }

        }
        return ans;
    }
};