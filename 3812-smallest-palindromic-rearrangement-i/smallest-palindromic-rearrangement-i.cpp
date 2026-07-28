class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq (26,0);

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        string left = "", mid = "";

        for (int i = 0; i < 26; i++) {
            
            while (freq[i] >= 2) {
                left += char('a' + i);
                freq[i] -= 2;
            }

            if (freq[i] == 1 && mid.empty()) {
                mid = char('a' + i);
                freq[i]--;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};