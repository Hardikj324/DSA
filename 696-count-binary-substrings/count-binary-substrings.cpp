class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int count = 0;
        int prev = 0;
        int curr = 0;
        int j = 0;
        int i = 0;
        
        while(i<n){
          if(s[i+1]!=s[i]){
            curr = i - j + 1;
            count += min(curr,prev);
            prev = curr;
            j = i + 1;
          }
          
          i++;
        }

        return count;
    }
};